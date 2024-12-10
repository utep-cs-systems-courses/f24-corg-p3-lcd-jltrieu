
	.data 

count:	 .word 0

.text
	.balign 2
	.global WDT
	.section __interrupt_vector_11,"ax"
	.word WDT
	.text

	.global count
	.extern redrawScreen
	.extern buzzer_timer_update
WDT:
	PUSH R15
	PUSH R14
	PUSH R13
	PUSH R12
	PUSH R11
	PUSH R10
	PUSH R9
	PUSH R8
	PUSH R7
	PUSH R6
	PUSH R5
	PUSH R4

	inc &count		;count++
	cmp #250, &count	; count - 250
	jnc done		; skip if count < 250
	call #buzzer_timer_update
	mov #1, &redrawScreen
	mov #0, &count	
done:	POP R4
	POP R5
	POP R6
	POP R7
	POP R8
	POP R9
	POP R10
	POP R11
	POP R12
	POP R13
	POP R14
	POP R15
	cmp #0, &redrawScreen
	jz dont_wake
	and #0xffef, 0(r1) 	; clear CPU off in saved SR
dont_wake:
	RETI
