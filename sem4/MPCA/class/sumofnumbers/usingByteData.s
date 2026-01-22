;find the sum of N numbers using conditional branch using Byte Data
.Data
	A: .Byte 10,20,30,40,50,60,70,80,90,11
	SUM: .WORD 0
.Text
	LDR R1,=A
	LDR R2,=SUM
	MOV R4,#0
	MOV R5,#1
	LOOP1: LDRB R3,[R1]
		ADD R1,R1,#1
		ADD R4,R4,R3
		ADD R5,R5,#1
		CMP R5,#11
		BNE LOOP1
	STRB R4,[R2]
	SWI 0x011

