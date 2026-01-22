MOV R0,#3 		@ Move the value 3 into register R0
MOV R1,#5 		@ Move the value 5 into register R1
MOV R3,#0x3000 	@ Move the address of the result into R3
ADD R2, R0, R1 	@ Add the content of R0 and R1, keep result in R2
STR R2,[R3] 		@ Store the content of R2 at the address in R3
