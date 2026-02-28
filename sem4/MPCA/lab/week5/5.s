; 5. Bubble Sort Algorithm
.DATA
ARRAY: .WORD 5,2,8,1,9,3,7,4,6
.EQU ARR_SIZE, 9
.TEXT
LDR R0,=ARRAY
MOV R1,#ARR_SIZE
SUB R1,R1,#1        ; R1 = n-1 (outer loop counter)
OUTER_LOOP:
    CMP R1,#0
    BEQ EXIT
    MOV R2,#0        ; R2 = inner loop counter
    LDR R3,=ARRAY
INNER_LOOP:
    CMP R2,R1
    BEQ INNER_DONE
    LDR R4,[R3]      ; Load current element
    LDR R5,[R3,#4]   ; Load next element
    CMP R4,R5
    BLE NO_SWAP
    STMFD R13!,{R0,R1,R2,R3,R4,R5,R14}   ; Preserve registers
    STR R5,[R3]                            ; Swap: store next in current
    STR R4,[R3,#4]                          ; Swap: store current in next
    LDMFD R13!,{R0,R1,R2,R3,R4,R5,R14}   ; Restore registers
NO_SWAP:
    ADD R3,R3,#4
    ADD R2,R2,#1
    B INNER_LOOP
INNER_DONE:
    SUB R1,R1,#1
    B OUTER_LOOP
EXIT: SWI 0X11
