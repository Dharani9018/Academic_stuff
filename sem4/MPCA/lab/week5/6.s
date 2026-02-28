; 6. Find the length of a string
.DATA
STRING: .ASCIZ "hiiiiiiiiiii"
.EQU STR_END, 0

.TEXT
LDR R0,=STRING
MOV R1,#0          ; R1 = length counter

LOOP:
    LDRB R2,[R0],#1              ; Load character
    CMP R2,#0                    ; Check for end of string
    BEQ EXIT
    ADD R1,R1,#1                  ; Increment length counter
    B LOOP

EXIT: SWI 0X11
