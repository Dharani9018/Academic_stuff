;LDMFA: increase and push -> IB
;STMFA: pop and decrease -> DA

.TEXT
    MOV R0, #1
    MOV R1, #2
    MOV R2, #3
    STMFA R13!, {R0, R1, R2}
    LDMFA R13!, {R3, R4, R5}
    SWI 0X11
