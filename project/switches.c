#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"

/* effectively boolean */
char SW1_state_down, SW2_state_down, SW3_state_down, SW4_state_down;
char state, state2;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;
}

void
switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  SW1_state_down = (p2val & SW1) ? 0 : 1;    /* 0 when switch is up */
  SW2_state_down = (p2val & SW2) ? 0 : 1;
  SW3_state_down = (p2val & SW3) ? 0 : 1;
  SW4_state_down = (p2val & SW4) ? 0 : 1;

  if(SW1_state_down){
    state = 1;
  }
  else if(SW2_state_down){
    state = 2;
  }
  else if(SW3_state_down){
    state = 3;
  }
  else if(SW4_state_down){
    state = 4;
  }
  if(state){
    state_advance();
    state = 0;
  }
}
