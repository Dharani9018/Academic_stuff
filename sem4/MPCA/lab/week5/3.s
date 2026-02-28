.DATA
FIB: .WORD 0,0,0,0,0,0,0,0,0,0

.TEXT
LDR R0,=FIB
MOV R1,#10         ; N = 10
MOV R2,#0          ; F0
MOV R3,#1          ; F1

CMP R1,#0
BEQ EXIT

STR R2,[R0],#4     ; store F0
SUBS R1,R1,#1
BEQ EXIT

STR R3,[R0],#4     ; store F1
SUBS R1,R1,#1
BEQ EXIT

LOOP:
    ADD R4,R2,R3   ; next = R2 + R3
    STR R4,[R0],#4
    MOV R2,R3
    MOV R3,R4
    SUBS R1,R1,#1
    BNE LOOP

EXIT:
SWI 0X11

