#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){          /* 250 interrupts/sec */
  static char count = 0;
  switch(state2){
  case 1:
    if(++count == 125){
      blink();
      count = 0;
    }
    break;
  case 2:
    if(++count == 125){
      redLed_toggle();
      count = 0;
    }
    break;
  case 3:
    if(++count == 1){
      redLed_toggle();
      count = 0;
    }
    break;
  }
}