#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "lcdutils.h"

char handleState;
int redrawScreen;

// Change graphics so that illuminait looks like its blinking
void blink(){
  static char s = 0;
  redrawScreen = 1;
  fillTriangle(10, 5*screenHeight/8, 110, COLOR_YELLOW);
  switch(s){
    // draw closed eye
  case 0:
    fillRectangle(45, screenHeight/2, 40, 5, COLOR_BLACK);
    s = 1;
    break;
    // draw open eye
  case 1:
    fillCircle(screenWidth/2, screenHeight/2, 20, COLOR_WHITE);
    fillCircle(screenWidth/2, screenHeight/2, 15, COLOR_BLACK);
    s = 0;
    break;
  }
}

// red led off
void redLed_Off(){
  red_on = 0;
  leds_changed = 1;
  led_update();
}

// red led on
void redLed_On(){
  red_on = 1;
  leds_changed = 1;
  led_update();
}

// turns red led on and off
void redLed_toggle(){
  static char redState = 0;
  switch(redState){
  case 0:
    redLed_On();
    redState = 1;
    break;
  case 1:
    redLed_Off();
    redState = 0;
    break;
  }
}

// Main state function
void state_advance(){
  redLed_Off();
  switch(buttonState){
    // enable WDT for blinking illuminati
  case 1:
    clearScreen(COLOR_BLUE);
    buttonState = 0;
    handleState = 1;
    break;
    // different color illuminati with music playing
  case 2:
    clearScreen(COLOR_BLACK);
    illuminati(COLOR_ROYAL_BLUE, COLOR_ROYAL_BLUE);
    song1();
    buttonState = 0;
    handleState = 2;
    break;
    // different color illuminati with music playing
  case 3:
    clearScreen(COLOR_WHITE);
    illuminati(COLOR_BLACK, COLOR_BLACK);
    song2();
    buttonState = 0;
    handleState = 3;
    break;
    // different color illuminati with design background
  case 4:
    clearScreen(COLOR_RED);
    dieBackground(COLOR_BLACK, COLOR_RED);
    illuminati(COLOR_BLACK, COLOR_BLACK);
    buttonState = 0;
    handleState = 4;
    break;
  }
}
