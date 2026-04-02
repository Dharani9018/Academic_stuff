<<<<<<< HEAD
.data
A:.BYTE 10
B:.BYTE 20
C:.BYTE 0
.TEXT
    LDR R1,=A
    LDR R2,=B
    LDR R3,=C 
    LDRB R4,[R1]
    LDRB R5,[R2]
    ADD R6,R4,R5
    STRB R6,[R3]
    SWI 0X11
=======
.data
A:.BYTE 10
B:.BYTE 20
C:.BYTE 0
.TEXT
    LDR R1,=A
    LDR R2,=B
    LDR R3,=C 
    LDRB R4,[R1]
    LDRB R5,[R2]
    ADD R6,R4,R5
    STRB R6,[R3]
    SWI 0X11
>>>>>>> 981fe96f5bd74891b42b1f36e81e31547d541f42
