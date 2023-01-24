; Push two values into the Stack
; Pop those values from the stack
; Add the Values and 
; put the result back into the stack

	.ORIG x3000
		
	AND R1, R1, #0	;initialize R1
	ADD R0, R1, #5	;put the value in R0 to be pushed
	JSR PUSH		;call PUSH subroutine
	ADD R5, R5, #0	;check for overflow	
	BRp Over_Flow	;if overflows display error message
					; and exit
	AND R2, R2, #0	;push the 2nd value
	ADD R0, R2, #3
	JSR PUSH
	ADD R5, R5, #0
	BRp Over_Flow

	AND R3, R3, #0	;pop the first value
	JSR POP			;call pop subroutine
	ADD R5, R5, #0	;check for underflow
	BRp Under_Flow	;if underflows exit with error message
	
	ADD R3,R0,#0	;pop the 2nd value
	AND R4, R4, #0
	JSR POP
	ADD R5, R5, #0
	BRp Under_Flow
	
	ADD R4,R0,#0
	ADD R0, R3, R4	;perform addition on two poped values
	JSR PUSH		;push the result onto stack
	JSR POP			;pop the result
	ADD R5, R5, #0	;error checking for underflow
	BRp Under_Flow

	LD R1, Ascii_BASE ;display the result
	ADD R0,R0,R1
	OUT

	BR EXIT

Over_Flow LEA R0, OverFlow_MSG
		 PUTS 
		 BR EXIT

OverFlow_MSG  .STRINGZ "There is an Overflow"

Under_Flow 	LEA R0, UnderFlow_MSG
			PUTS 
			BR EXIT

UnderFlow_MSG  .STRINGZ "There is an Underflow"
Ascii_BASE 	   .FILL x30

EXIT 	HALT

;----------------------PUSH/POP-----------------------------
;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R6: STACK_TOP
;
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R6, PUSH_SaveR6	;save R6
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R6, STACK_TOP	;
	ADD R3, R3, #-1		; Stack End Decremented by 1
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R6		;
	BRz OVERFLOW		;stack is full
	STR R0, R6, #0		;no overflow, store value in the stack
	ADD R6, R6, #-1		;move top of the stack
	ST R6, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R6, PUSH_SaveR6	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR6	.BLKW #1	;


;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3: STACK_START, R6: STACK_TOP
;
POP	
	ST R3, POP_SaveR3	;save R3
	ST R6, POP_SaveR6	;save R6
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R6, STACK_TOP	;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R6		;
	BRz UNDERFLOW		;
	ADD R6, R6, #1		;
	LDR R0, R6, #0		;
	ST R6, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R6, POP_SaveR6	;
	RET


POP_SaveR3	.BLKW #1	;
POP_SaveR6	.BLKW #1	;
STACK_END	.FILL x3FFE	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;


.END