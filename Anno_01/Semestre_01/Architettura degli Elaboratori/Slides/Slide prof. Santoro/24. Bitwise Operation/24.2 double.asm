
data      dcd     1,5,9,2,3,5,8,7

          ;       raddoppia tutti gli elementi dell'array
          ;       r0 = contatore elementi
          ;       r1 = ptr elemento corrente dell'array
          ;       r3 = elemento corrente
          ;
          mov     r0,#8
          mov     r1,#data
loop      
          cmp     r0,#0
          beq     exit_loop
          ldr     r3,[r1]
          lsl     r3,r3,#1
          str     r3,[r1],#4
          sub     r0,r0,#1
          b       loop
exit_loop 
          end
