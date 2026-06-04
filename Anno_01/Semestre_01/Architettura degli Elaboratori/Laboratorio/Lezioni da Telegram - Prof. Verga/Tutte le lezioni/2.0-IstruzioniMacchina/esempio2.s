num       dcd     1,2,3,4,67,100
costante  equ     35
risultato fill    4
          mov     r1,#num
          ldr     r2,[r1]
          add     r1,r1,#4
          ldr     r3,[r1]
          add     r3,r3,#costante
          mov     r5,#31
          mov     r1,#risultato
          str     r5,[r1]
          end

