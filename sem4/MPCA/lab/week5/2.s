; 2. Transfer a 3×3 matrix from location A to location C
.DATA
A: .WORD 1,2,3,4,5,6,7,8,9
C: .WORD 0,0,0,0,0,0,0,0,0
.TEXT
LDR R0,=A
LDR R1,=C
MOV R2,#0          ; R2 = i (row counter)
MOV R3,#0          ; R3 = j (column counter)
OUTER_LOOP:
    CMP R2,#3
    BEQ EXIT
    MOV R3,#0
INNER_LOOP:
    CMP R3,#3
    BEQ INNER_DONE
    STMFD R13!,{R0,R1,R2,R3,R4,R5,R6,R14}   ; Preserve registers
    BL CALC_SRC_ADDR
    LDR R4,[R0]                              ; Load from source
    BL CALC_DST_ADDR
    STR R4,[R1]                              ; Store to destination
    LDMFD R13!,{R0,R1,R2,R3,R4,R5,R6,R14}   ; Restore registers
    ADD R3,R3,#1
    B INNER_LOOP
INNER_DONE:
    ADD R2,R2,#1
    B OUTER_LOOP
CALC_SRC_ADDR:
    MOV R5,R2
    MOV R6,#3
    MLA R7,R5,R6,R3
    MOV R5,R7,LSL #2
    LDR R0,=A
    ADD R0,R0,R5
    MOV PC,R14
CALC_DST_ADDR:
    MOV R5,R2
    MOV R6,#3
    MLA R7,R5,R6,R3
    MOV R5,R7,LSL #2
    LDR R1,=C
    ADD R1,R1,R5
    MOV PC,R14
EXIT: SWI 0X11
