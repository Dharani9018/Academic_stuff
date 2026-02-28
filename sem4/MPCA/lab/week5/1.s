; 1. Write an ARM assembly language program to compute the sum of all elements in a 3×3 matrix
.DATA
MATRIX: .WORD 1,1,1,1,1,1,1,1,1

.TEXT
LDR R0,=MATRIX
MOV R1,#0          ; R1 = i (row counter)
MOV R2,#0          ; R2 = j (column counter)
MOV R3,#0          ; R3 = total sum
MOV R4,#3          ; R4 = matrix size (3x3)

OUTER_LOOP:
    CMP R1,#3
    BEQ EXIT ;if row = 3 exit or else make column index = 0 and enter inner loop
    MOV R2,#0
INNER_LOOP:
    CMP R2,#3
    BEQ INNER_DONE
    STMFD R13!,{R0,R1,R2,R4,R14}   
    BL CALC_ADDR
    LDR R5,[R0]                    
    ADD R3,R3,R5                   
    LDMFD R13!,{R0,R1,R2,R4,R14}   
    ADD R2,R2,#1
    B INNER_LOOP
INNER_DONE:
    ADD R1,R1,#1
    B OUTER_LOOP

CALC_ADDR:
    ; Calculate address = base + (i*3 + j)*4
    MOV R6,R1                        ; R6 = i
    MOV R7,#3
    MLA R8,R6,R7,R2                   ; R6 = i*3 + j
    MOV R6,R8,LSL #2                  ; Multiply by 4
    LDR R0,=MATRIX
    ADD R0,R0,R6
    MOV PC,R14

EXIT: SWI 0X11
