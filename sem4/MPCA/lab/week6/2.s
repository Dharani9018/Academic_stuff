;Write an ARM7TDMI assembly language program to multiply two matrices of suitable order and store the result in a separate memory location.
.DATA 
A: .WORD 1,2,3,4,5,6
B: .WORD 1,5,2,6,3,7,4,8
RES: .WORD 0,0,0,0,0,0,0,0,0,0,0,0
.TEXT
LDR R0,=A
LDR R1,=B
LDR R2,=RES
MOV R3,#0
OUTER:
	MOV R4,#0
INNER:
MOV R5,#0
MOV R6,#0
ELEM:
LDR R7,[R0,R5,LSL#2]
LDR R8,[R1,R6,LSL#2]
MLA R9,R7,R8,R9
ADD R5,R5,#1
ADD R6,r6,#2
CMP R5,#2
BNE ELEM
STR R9,[R2],#4
ADD R4,r4,#1
CMP R4,#4
BNE INNER
ADD R3,r3,#1
CMP R3,#3
BNE OUTER
SWI 0x11
