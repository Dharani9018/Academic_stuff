;Write an ARM7TDMI assembly language program to generate the first N terms of an arithmetic progression and store them in memory.
        .DATA
N:      .WORD 10
FIRST:  .WORD 5
DIFF:   .WORD 3
SERIES: .SPACE 40

        .TEXT

        LDR R0, =N
        LDR R0, [R0]
        LDR R1, =FIRST
        LDR R1, [R1]
        LDR R2, =DIFF
        LDR R2, [R2]
        LDR R3, =SERIES

        MOV R4, #0

LOOP:   STR R1, [R3, R4, LSL #2]
        ADD R1, R1, R2
        ADD R4, R4, #1
        CMP R4, R0
        BNE LOOP

        SWI 0x11
