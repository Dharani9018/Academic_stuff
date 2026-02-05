.DATA
A: .WORD 10,20,30,40,50
B: .WORD 10,20,30,40,50

.TEXT
LDR R0,=A        
LDR R1,=B        
MOV R4,#5        
MOV R5,#0        

LOOP: 
    LDR R2,[R0],#4    
    LDR R3,[R1],#4    
    MUL R6,R2,R3      
    ADD R5,R5,R6      
    SUBS R4,R4,#1     
    CMP R4,#0         
    BEQ EXIT          
    B LOOP            

EXIT: SWI 0X11        
