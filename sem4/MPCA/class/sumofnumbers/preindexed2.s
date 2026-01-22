;auto indexed addressing (pre-indexed without write back)
.Data
	A: .WORD 10,20,30,40,50,60,70,80,90,100
	SUM: .WORD 00
.Text
	LDR R1,=A
	LDR R2,=SUM
	MOV R4,#0
	MOV R5,#1
	LDR R4,[R1]
	LOOP1:	LDR R3,[R1,#4]! @pre-indexing with write back
		ADD R4,R4,R3
		ADD R5,R5,#1
		CMP R5,#11
		BNE LOOP1
	STR R4,[R2]
	SWI 0x011

