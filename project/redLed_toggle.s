	#include <msp430.h>
	#include "stateMachines.h"
	#include "led.h"

				;The redLed_toggle method from stateMachines.c in assembly
	.global redLed_toggle

redState:	.byte 0

red_on:		.byte 0

	.text
jt:
	.word case1
	.word case2

redLed_toggle:
	mov.b #3, &redState
	jnc end

	mov &state, r12
	add r12, r12
	mov jt(r12), r0
	
case1:
	call #redLed_On
	mov #2, r12
	jmp end

case2:
	call #redLed_Off
	mov #1, r12
	jmp end

end:	
	ret
