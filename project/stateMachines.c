#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "lcdutils.h"

void song1(){
  int song1[25] = {1760,0,0,0,2637,0,0,0,2349,0,0,0,2637,0,0,0,2637,0,0,0,1760,0,0,0,2637};
  for(int i = 0; i < 26; i++){
    buzzer_set_period(song1[i]);
    __delay_cycles(1800000);
  }
  buzzer_set_period(0);
}

void song2(){
  int song2[49] = {1109,0,1109,0,987,0,987,0,880,0,0,0,0,0,0,0,987,0,1109,0,0,0,740,0,0,0,0,0,0,0,740,0,659,0,0,0,659,0,1109,0,0,0,1109,0,0,0,987,0,880};
  for(int i = 0; i < 50; i++){
    buzzer_set_period(song2[i]);
    __delay_cycles(1800000);
  }
  buzzer_set_period(0);
}

void blink(){
  static char s = 0;
  fillTriangle(10, 5*screenHeight/8, 110, COLOR_YELLOW);
  switch(s){
  case 0:
    fillRectangle(45, screenHeight/2, 40, 5, COLOR_BLACK);
    s = 1;
    break;
  case 1:
    fillCircle(screenWidth/2, screenHeight/2, 20, COLOR_WHITE);
    fillCircle(screenWidth/2, screenHeight/2, 15, COLOR_BLACK);
    s = 0;
    break;
  }
}

void redLed_Off(){
  red_on = 0;
  leds_changed = 1;
  led_update();
}

void redLed_On(){
  red_on = 1;
  leds_changed = 1;
  led_update();
}

void redLed_toggle(){
  static char lul = 0;
  switch(lul){
  case 0:
    redLed_On();
    lul = 1;
    break;
  case 1:
    redLed_Off();
    lul = 0;
    break;
  }
}

void state_advance(){
  redLed_Off();
  switch(state){
  case 1:
    redrawScreen = 1;
    state2 = 1;
    clearScreen(COLOR_BLUE);
    break;
  case 2:
    redrawScreen = 1;
    clearScreen(COLOR_BLACK);
    illuminati(COLOR_ROYAL_BLUE, COLOR_ROYAL_BLUE);
    song1();
    state2 = 2;
    break;
  case 3:
    redrawScreen = 1;
    clearScreen(COLOR_WHITE);
    illuminati(COLOR_BLACK, COLOR_BLACK);
    song2();
    state2 = 3;
    break;
  case 4:
    redrawScreen = 1;
    clearScreen(COLOR_RED);
    dieBackground(COLOR_BLACK, COLOR_RED);
    illuminati(COLOR_BLACK, COLOR_BLACK);
    state2 = 0;
    break;
  }
}
