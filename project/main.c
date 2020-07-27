#include "msp430.h"
#include "lcdutils.h"
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachines.h"

#define RED_LED BIT0

int redrawScreen = 1;

int
main()
{
  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();
  
  clearScreen(COLOR_WHITE);
  drawString8x12(40, 60, "HELLO" , COLOR_BLACK, COLOR_WHITE);
  drawString8x12(40, 80, "HUMAN", COLOR_BLACK, COLOR_WHITE);

  //enableWDTInterrupts();
  or_sr(0x8);
  /*
  for(;;) {
    while(!redrawScreen){
      P!OUT &= ~RED_LED;
      or_sr(0x10);
    }
    P1OUT |= RED_LED;
    redrawScreen = 0;
    state_advance();
  }
  */
}
