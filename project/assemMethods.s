	.arch msp430g2553
	.p2align 1,0

	.data
redState:
	.byte 0

	.text
jt:
	.word case1
	.word case2

	.global redLed_toggle   ; The redLed_toggle method from stateMachines.c in assembly
redLed_toggle:
	cmp.b #2, &redState
	jhs end

	mov.b &redState, r12
	add.b r12, r12
	mov jt(r12), r0
	
case1:
	call #redLed_On
	mov.b #1, r12
	mov.b #1, &redState
	jmp end

case2:
	call #redLed_Off
	mov.b #0, r12
	mov.b #0, &redState
	jmp end

end:	
	pop r0
