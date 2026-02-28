        .DATA
STR1:   .ASCIZ "HELLO"
BEFORE: .ASCIZ "Before: "
AFTER:  .ASCIZ "After: "

        .TEXT

        LDR R0, =BEFORE
        SWI 0x02

        LDR R0, =STR1
        SWI 0x02

        LDR R1, =STR1
        MOV R2, R1

FIND:   LDRB R3, [R2]
        CMP R3, #0
        BEQ ENDSTR
        ADD R2, R2, #1
        B FIND

ENDSTR: SUB R2, R2, #1

        LDRB R4, [R1]
        LDRB R5, [R2]

        STRB R5, [R1]
        STRB R4, [R2]
        LDR R0, =AFTER
        SWI 0x02
        LDR R0, =STR1
        SWI 0x02
        SWI 0x11
