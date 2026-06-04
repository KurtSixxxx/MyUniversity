          ;Data   la lista 1,24,12,8,10,1,4,21,3,1,5,1
          ;sommarei numeri maggiori (o uguali) di x
          ;       con x = 10

lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim       equ     12
risultato fill    4
costante  equ     10

          mov     r1,#lista
          mov     r2,#dim
          mov     r3,#risultato
          mov     r9,#0 ; clear
ciclo     ldr     r4,[r1],#4
          cmp     r4,#costante
          bge     sommare
continua  subs    r2,r2,#1
          bgt     ciclo
          str     r9,[r3]
          end
sommare   add     r9,r9,r4
          b       continua