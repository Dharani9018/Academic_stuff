;push , inc
.TEXT
	MOV R0,#4
	MOV R1,#5
	MOV R2,#6
	STMEA R13!,{R0,R1,R2}
	LDMEA R13!,{R5,R6,R7} ;or use LDMDB
.END
