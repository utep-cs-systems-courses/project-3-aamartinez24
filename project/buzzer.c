#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
  /*
    Direct timer A output "TA0.a" to p2.6.
    According to table 21 from data sheet:
      P2SEL2.6, P2SEL2.7, and P2SEL.7 must be zero
      P2SEL.6 must be 1
    Also: P2.6 direction must be output
  */
  timerAUpmode();              /* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;                /* enable output to speacker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz. (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;          /* one half cycle */
}

// Plays a short song
void song1(){
  int song1[25] = {1760,0,0,0,2637,0,0,0,2349,0,0,0,2637,0,0,0,2637,0,0,0,1760,0,0,0,2637};
  for(int i = 0; i < 26; i++){
    buzzer_set_period(song1[i]);
    __delay_cycles(1800000);
  }
  buzzer_set_period(0);
}

// Plays another short song
void song2(){
  int song2[49] = {1109,0,1109,0,987,0,987,0,880,0,0,0,0,0,0,0,987,0,1109,0,0,0,740,0,0,0,0,0,0,0,740,0,659,0,0,0,659,0,1109,0,0,0,1109,0,0,0,987,0,880};
  for(int i = 0; i < 50; i++){
    buzzer_set_period(song2[i]);
    __delay_cycles(1800000);
  }
  buzzer_set_period(0);
}
