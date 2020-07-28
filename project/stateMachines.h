#ifndef stateMachine_included
#define stateMachine_included

void state_advance();
void blink();
void redLed_toggle();

extern char state, state2;
extern int redrawScreen;

#endif
