#ifndef stateMachine_included
#define stateMachine_included

void state_advance();
void blink();
void redLed_On();
void redLed_Off();
//void redLed_toggle();

extern char buttonState, handleState;

#endif
