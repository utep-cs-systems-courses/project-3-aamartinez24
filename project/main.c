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
  __delay_cycles(300000);
  redrawScreen = 0;
  }
}
