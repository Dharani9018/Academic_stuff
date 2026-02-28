; 4. Count the number of words in a string
.DATA
STRING: .ASCII "Hiiiiiiii"
.EQU STR_END, 0

.TEXT
LDR R0,=STRING
MOV R1,#0          ; R1 = word counter
MOV R2,#0          ; R2 = flag (0 = not in word, 1 = in word)

LOOP:
    LDRB R3,[R0],#1              ; Load character
    CMP R3,#0                    ; Check for end of string
    BEQ EXIT
    CMP R3,#' '                  ; Check for space
    BEQ SPACE
    CMP R2,#0                    ; Check if not in word
    BNE SKIP
    ADD R1,R1,#1                  ; Increment word counter
    MOV R2,#1                      ; Set flag to in word
    B SKIP
SPACE:
    MOV R2,#0                      ; Set flag to not in word
SKIP:
    B LOOP

EXIT: SWI 0X11
