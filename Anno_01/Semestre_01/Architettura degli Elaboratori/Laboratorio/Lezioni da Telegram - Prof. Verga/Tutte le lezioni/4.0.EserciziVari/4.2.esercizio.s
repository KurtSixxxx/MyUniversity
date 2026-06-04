           ;       Moltiplicare i numeri 9,3

fattore1   dcd     9
fattore2   dcd     3
moltiplico fill    4

           mov     r1,#fattore1
           ldr     r1,[r1]
           mov     r2,#fattore2
           ldr     r2,[r2]
           mov     r3,#moltiplico
           mov     r4,#0 ;sommatoria

ciclo      add     r4,r4,r1
           subs    r2,r2,#1
           bgt     ciclo

           str     r4,[r3]
