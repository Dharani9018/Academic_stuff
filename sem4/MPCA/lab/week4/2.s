.DATA
MATRIX: .WORD 0,0,0,0,0,0,0,0,0

.TEXT
LDR R0,=MATRIX
MOV R1,#2
MOV R2,#0
MOV R3,#3

LOOP1:
    MOV R4,#0
    LOOP2:
        CMP R2,R4
        BNE SKIP
        STR R1,[R0]
        SKIP:
        ADD R0,R0,#4
        ADD R4,R4,#1
        CMP R4,R3
        BNE LOOP2
    ADD R2,R2,#1
    CMP R2,R3
    BNE LOOP1

EXIT: SWI 0X11
