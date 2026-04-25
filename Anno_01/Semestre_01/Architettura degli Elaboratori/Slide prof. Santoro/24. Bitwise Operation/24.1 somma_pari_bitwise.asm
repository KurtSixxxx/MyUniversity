
data      dcd     1,5,9,2,3,5,8,7

        ;  somma elementi pari
          ;       r0 = contatore elementi
          ;       r1 = ptr elemento corrente dell'array
          ;       r2 = somma parziale
          ;       r3 = elemento corrente
          ;
          mov     r0,#8
          mov     r1,#data
          mov     r2,#0
loop      
          cmp     r0,#0
          beq     exit_loop
          ldr     r3,[r1]
          and     r4,r3,#1
          cmp     r4,#0
          bne     skip
          add     r2,r2,r3
skip      
          add     r1,r1,#4
          sub     r0,r0,#1
          b       loop
exit_loop 
          end