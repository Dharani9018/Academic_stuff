<<<<<<< HEAD
@Based on value of number in r0

.TEXT
LDR R0,=0X10
MOV R0,#-1
CMP R0,#0
BEQ ZERO
BGT POS

NEG: MOV R1,#3
B EXIT

ZERO: MOV R1,#1
B EXIT

POS: MOV R1,#2

=======
@Based on value of number in r0

.TEXT
LDR R0,=0X10
MOV R0,#-1
CMP R0,#0
BEQ ZERO
BGT POS

NEG: MOV R1,#3
B EXIT

ZERO: MOV R1,#1
B EXIT

POS: MOV R1,#2

>>>>>>> 981fe96f5bd74891b42b1f36e81e31547d541f42
EXIT:SWI 0X011