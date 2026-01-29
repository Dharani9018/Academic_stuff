.Data
	A: .WORD 1,2,3,4,5,6,7,8,9,10
	SUM: .WORD 0
.Text
	LDR R1,=A
	LDR R2,=SUM
	MOV R4,#0
	LDR R4,[R1]
	MOV R5,#1
	LOOP1:	LDR R3,[R1, #8] @pre-indexing without write back
		ADD R4,R4,R3
		ADD R1,R1,#8
		ADD R5,R5,#1
		CMP R5,#5
		BNE LOOP1
	STR R4,[R2]
	SWI 0x011

