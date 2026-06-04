lista      dcd     10
costante   equ     15

           mov     r1,#lista
           ldr     r2,[r1]
           bl      sommatoria
           mov     r4,#10
           end


sommatoria add     r2,r2,#costante
           mov     pc,lr