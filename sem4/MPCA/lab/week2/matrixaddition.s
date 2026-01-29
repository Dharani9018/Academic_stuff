;Write an ALP to find the number of zeroes, positive and negative numbers in a given array
.DATA
	A:.WORD 1,1,1,1,1,1,1,1,1
	B:.WORD 1,2,3,4,5,6,7,8,9
	C:.WORD 0,0,0,0,0,0,0,0,0
.TEXT
	LDR R0,=A
	LDR R2,=B
	LDR R6,=C
	MOV R4,#9
	LOOP:
		LDR R3,[R2]
		LDR R1,[R0]
		ADD R5,R3,R1;
		STR R5,[R6]
		ADD R0,R0,#4
		ADD R2,R2,#4
		ADD R6,R6,#4
		SUBS R4,R4,#1
		BNE LOOP
	SWI 0X11

			

