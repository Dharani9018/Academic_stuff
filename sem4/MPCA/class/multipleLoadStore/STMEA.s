<<<<<<< HEAD
;push , inc
.TEXT
	MOV R0,#4
	MOV R1,#5
	MOV R2,#6
	STMEA R13!,{R0,R1,R2}
	LDMEA R13!,{R5,R6,R7} ;or use LDMDB
.END
=======
.TEXT
	MOV R0,#4
	MOV R1,#5
	STMEA R13!,{R0,R1}
	LDMEA R13!,{R5,R6} ;or use LDMDB
.END
>>>>>>> 981fe96f5bd74891b42b1f36e81e31547d541f42
