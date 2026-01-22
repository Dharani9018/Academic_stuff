;find the sum of N numbers using conditional branch using half word
.Data
	A: .HWORD 10,20,30,40,50,60,70,80,90,11
	SUM: .WORD 00
.Text
	LDR R1,=A
	LDR R2,=SUM
	MOV R4,#0
	MOV R5,#1
	LOOP1: LDRH R3,[R1]
		ADD R1,R1,#2
		ADD R4,R4,R3
		ADD R5,R5,#1
		CMP R5,#11
		BNE LOOP1
	STRH R4,[R2]
	SWI 0x011

