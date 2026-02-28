        .DATA
NUM:    .WORD 12345
SUM:    .WORD 0

        .TEXT

        LDR R0, =NUM
        LDR R0, [R0]
        MOV R1, #0
        MOV R2, #10

LOOP:   CMP R0, #0
        BEQ DONE

        MOV R3, #0

DIV:    CMP R0, R2
        BLT REM
        SUB R0, R0, R2
        ADD R3, R3, #1
        B DIV

REM:    ADD R1, R1, R0
        MOV R0, R3
        B LOOP

DONE:   LDR R4, =SUM
        STR R1, [R4]
        SWI 0x11
