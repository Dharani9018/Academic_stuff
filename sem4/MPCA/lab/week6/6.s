        .DATA
a:      .WORD 6
b:      .WORD 25
z:      .WORD 0

        .TEXT

        LDR R0, =a
        LDR R0, [R0]

        LDR R1, =b
        LDR R1, [R1]

        MOV R2, R0, LSL #2
        AND R3, R1, #15
        ORR R4, R2, R3

        LDR R5, =z
        STR R4, [R5]

        SWI 0x11
