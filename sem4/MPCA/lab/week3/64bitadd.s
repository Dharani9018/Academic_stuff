mov r0, #0xFFFFFFFF @r0=r1=r2=r4= maximum unsigned 32bit value(32 ones) 1111..
mov r1, #0xFFFFFFFF 
mov r2, #0xFFFFFFFF
mov r3, #0xFFFFFFFF
ADDS r4, r0,r2  
ADC r5, r1,r3 
