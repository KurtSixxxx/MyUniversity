LISTA  DCD     1,20,20,20,2,18,30,27,3,22,26,28
DIM    DCD     3
VOTI   FILL    12
TEST   DCD     1020

       MOV     R1,#LISTA
       MOV     R2,#DIM
       LDR     R2,[R2]
       MOV     R3,#VOTI

       MOV     R6,#0 ;SOMMA VOTO 1
       MOV     R7,#0 ;SOMMA VOTO 2
       MOV     R8,#0 ;SOMMA VOTO 3

CICLO  ADD     R1,R1,#4
       LDR     R4,[R1],#4
       ADD     R6,R6,R4
       ;ADD    R1,R1,#4
       LDR     R4,[R1]
       ADD     R7,R7,R4
       ADD     R1,R1,#4
       LDR     R4,[R1]
       ADD     R8,R8,R4
       ADD     R1,R1,#4

       SUBS    R2,R2,#1
       BGT     CICLO

       STR     R6,[R3]
       STR     R7,[R3,#4]
       STR     R8,[R3,#8]




