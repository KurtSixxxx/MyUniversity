          ;       Data la lista [30,10,23,1,17,8,19,10]
          ;sommaretutti i numeri compresi tra 10 e 20.

lista     dcd     30,10,23,1,17,8,19,10
dim       dcd     8
risultato fill    4

          mov     r1,#lista
          mov     r2,#dim
          ldr     r2,[r2]
          mov     r5,#0 ;sommatore
ciclo     subs    r2,r2,#1
          blt     esci
          ldr     r3,[r1],#4
          cmp     r3,#20
          bgt     ciclo
          cmp     r3,#10
          blt     ciclo
          add     r5,r5,r3
          b       ciclo
esci      mov     r1,#risultato
          str     r5,[r1]


