;Write an ALP to find the number of zeroes, positive and negative numbers in a given array
.DATA
	A:.WORD 0,0,-1,-1,2,2
.TEXT
	LDR R0,=A
	MOV R1,#0 ;ZEORES
	MOV R2,#0 ;POSITIVES
	MOV R3,#0 ;NEGATIVES
	MOV R4,#6
	LOOP:
		LDR R5,[R0]
		CMP R5,#0
		BEQ ZEROES
		BGT POS
		BLT NEG
	CHECK:
		ADD R0,R0,#4
		SUBS R4,R4,#1
		BGT LOOP
		BEQ EXIT
	ZEROES:
		ADD R1,R1,#1
		B CHECK

	POS:
		ADD R2,R2,#1
		B CHECK
	NEG:
		ADD R3,R3,#1
		B CHECK
		
	EXIT:
		SWI 0X11
	

