;128 bit addition
mov r0, #0xFFFFFFFF @r0=r1=r2=r4= maximum unsigned 32bit value(32 ones) 1111..
mov r1, #0xFFFFFFFF 
mov r2, #0xFFFFFFFF
mov r3, #0xFFFFFFFF
mov r4, #0xFFFFFFFF
mov r5, #0xFFFFFFFF
mov r6, #0xFFFFFFFF
mov r7, #0xFFFFFFFF
ADDS r4,r0,r4  
ADC r5,r1,r5
ADC r6,r2,r6
ADC r7,r7,r3



