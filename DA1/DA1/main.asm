;
; DA1.asm
;
; Created: 2/13/2019 1:16:50 PM
; Author : YKengne
;


; Test hardware multiplication 16-by-8-bit
;
; Register definitions:
;
.def Res1 = R18
.def Res2 = R19
.def Res3 = R20
.def m1L = R22
.def m1M = R24
.def m2 = R25

;First we load the numbers:

;
; Load Registers
;
.equ m1 = 10000
;
	ldi m1M,HIGH(m1) ; upper 8 bits of m1 to m1M
	ldi m1L,LOW(m1) ; lower 8 bits of m1 to m1L
	ldi m2,100 ; 8-bit constant to m2



;Then we multiply the LSB first:

;
; Multiply
;
	mul m1L,m2 ; Multiply LSB
	mov Res1,R0 ; copy result to result register
	mov Res2,R1
	

;Now the multiplication of the MSB of m1 with m2 follows:

	mul m1M,m2 ; Multiply MSB


	mov Res3,R1 ; copy MSB result to result byte 3
	add Res2,R0 ; add LSB result to result byte 2
	brcc NoInc ; if not carry, jump
	inc Res3
NoInc: