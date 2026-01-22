;Convert the C statement to arm if(ro!=5) {r1 = r1+r0-r2}
MOV R0,#5
MOV R1, #6
MOV R2,#3
CMP R0,R1
ADDEQ R1,R1,R0
SUBNE R1,R1,R2
SWI 0X011
