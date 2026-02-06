@ even or odd
@ if even copy 00 to r0
@ else copy ff to r0
mov r1, #0x05
ands r2,r1, #0x01 @s-> update the status register, only wrt to lsb, if lsb=1, Z flag!=0 lsb = 0, Z Flag = 0.
beq loc1 @b-> branch
mov r0, #0xFF
    b loc2
loc1: mov r0,#0x00
loc2: swi 0x11
