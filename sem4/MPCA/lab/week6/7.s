        .DATA
STR:        .ASCIZ "HELLO"
REVSTR:     .SPACE 20
MSG1:       .ASCIZ "Before: "
MSG2:       .ASCIZ "\nAfter: "
LEN:        .WORD 0

        .TEXT

        LDR R0, =MSG1
        SWI 0x02
        LDR R0, =STR
        SWI 0x02

        LDR R0, =STR
        LDR R1, =REVSTR
        BL STRING_PROC

        LDR R0, =MSG2
        SWI 0x02
        LDR R0, =REVSTR
        SWI 0x02

        SWI 0x11

STRING_PROC:
        STMFD SP!, {R4,LR}
        MOV R4, R0
        BL LENGTH
        LDR R2, =LEN
        STR R0, [R2]
        MOV R0, R4
        BL REVERSE
        LDMFD SP!, {R4,LR}
        BX LR

LENGTH:
        STMFD SP!, {R1,R2,LR}
        MOV R1, R0
        MOV R0, #0
L1:
        LDRB R2, [R1], #1
        CMP R2, #0
        BEQ L2
        ADD R0, R0, #1
        B L1
L2:
        LDMFD SP!, {R1,R2,LR}
        BX LR

REVERSE:
        STMFD SP!, {R2-R6,LR}
        MOV R2, R0
        MOV R3, #0
R1:
        LDRB R4, [R2, R3]
        CMP R4, #0
        BEQ R2_END
        ADD R3, R3, #1
        B R1
R2_END:
        SUB R3, R3, #1
        MOV R5, #0
R3:
        CMP R3, #-1
        BEQ R4
        LDRB R6, [R2, R3]
        STRB R6, [R1, R5]
        ADD R5, R5, #1
        SUB R3, R3, #1
        B R3
R4:
        MOV R6, #0
        STRB R6, [R1, R5]
        LDMFD SP!, {R2-R6,LR}
        BX LR
