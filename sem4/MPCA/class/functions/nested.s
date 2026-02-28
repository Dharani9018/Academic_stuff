; mul(ADD(A,B),C) -> (A+B)*C
.DATA
	A:.WORD 0
.TEXT
	MOV R0,#1
	MOV R1,#2
	MOV R2,#3

	STMFD R13!,{R0,R1,R2} ;decrement and push

	BL MULFUNC

	LDR R6,=A
	STR R7,[R6]
	SWI 0X11

	MULFUNC:
		LDMFD R13!,{R3,R4,R5}
		STMFD R13!,{R3,R4,LR}
		BL ADDFUNC
		LDMFD R13!,{LR}
		MUL R7,R8,R5
		MOV PC,LR
	ADDFUNC:
		LDMFD R13!,{R6,R7}
		ADD R8,R6,R7
		MOV PC,LR
