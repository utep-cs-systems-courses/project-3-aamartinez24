#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT() {/* 250 interrupts/sec */
  static char blink_count = 0;
  char beat = 68; // Represents the needed interrupts for an eighth note

  if(++blink_count == beat) {
    blink();
    blink_count = 0;
  }
}
