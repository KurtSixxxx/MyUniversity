          ;       Data la lista [10,20,12,12,5,1,5,1] contare tutti i numeri diversi da 1 e 10.

num       dcd     10,20,12,12,5,1,5,1
dim       equ     8
risultato fill    4

          mov     r1, #num ;lista
          mov     r3, #dim ;dimensione
          mov     r0, #0 ;contatore
          mov     r5, #risultato

ciclo     cmp     r3, #0
          beq     endciclo
          ldr     r2, [r1], #4
          cmp     r2, #1
          beq     nextitem
          cmp     r2, #10
          beq     nextitem

          add     r0, r0, #1

nextitem  sub     r3, r3, #1
          b       ciclo

endciclo  str     r0, [r5]
          end