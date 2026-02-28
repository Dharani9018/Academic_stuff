;write an arm7tdmi assembly program using nested procedure calls to compute the sum of squares of two numbers. the main program calls a procedure sum_sq, which in turn calls another procedure square to compute the square of a number.
.text
	mov r0,#3
	mov r1,#2
	mov r2,#0 ;result
	stmfd r13!,{r0,r1} ;decrement and push
	bl sum_sq
	mov r2,r7
	swi 0x11
	sum_sq:
		ldmfd r13!,{r3,r4}
		stmfd r13!,{r3,r4,lr}
		bl square
		ldmfa r13!,{lr}
		add r7,r8,r7
		mov pc,lr
	square:
		ldmfd r13!,{r5,r6}
		mul r7,r5,r5
		mul r8,r6,r6
		mov pc,lr

		
		
