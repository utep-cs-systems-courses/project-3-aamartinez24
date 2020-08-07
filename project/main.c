#include "msp430.h"
#include "lcdutils.h"
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"
#include "stateMachines.h"
#include "lcddraw.h"

int redrawScreen = 1;

int
main()
{
  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;
  
  configureClocks();
  lcd_init();
  switch_init();
  led_init();
  buzzer_init();
  
  clearScreen(COLOR_WHITE);
  drawString8x12(40, 60, "HELLO" , COLOR_BLACK, COLOR_WHITE);
  drawString8x12(40, 80, "HUMAN", COLOR_BLACK, COLOR_WHITE);
  
  enableWDTInterrupts(); 
  
  or_sr(0x8);

  for(;;){
    while(!redrawScreen){
      P1OUT &= ~LED_GREEN;
      or_sr(0x10);
    }
    P1OUT |= LED_GREEN;
    __delay_cycles(30000);
    redrawScreen = 0;
    }
}

void wdt_c_handler()
{
  static short count = 0;
  count++;
  if(count == 125){
    state_advance();
    if(handleState == 1){
      // first switch: change lcd dispaly
      blink();
    }
    if(handleState == 2){
      // second switch: blink red led
      redLed_toggle();
    }
    count = 0;
  }
  if(handleState == 3){
    if(count == 1){
      state_advance();
      // third switch: blink red led fast(dim)
      redLed_toggle();
      count = 0;
    }
  }
}
