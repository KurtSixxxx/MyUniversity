          ;Data   la lista 1,24,12,8,10,1,4,21,3,1,5,1
          ;contareil numero di volte che compare
          ;in     memoria il valore 1 e salvare il risultato
          ;in     memoria.

lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim       equ     12
risultato fill    4
costante  equ     1

          mov     r1,#lista
          mov     r2,#dim
          mov     r4,#0 ;clear

ciclo     ldr     r3,[r1],#4
          ;add    r1,r1,#4
          cmp     r3,#costante
          beq     contatore
continua  subs    r2,r2,#1
          bgt     ciclo

contatore add     r4,r4,#1
          b       continua

