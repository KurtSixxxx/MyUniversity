lista  dcd     1,2,3,4
dim    dcd     4
somma  fill    4

       mov     r1,#dim
       ldr     r1,[r1]
       mov     r2,#lista
       mov     r8,#0 ;clear
ciclo  ldr     r3,[r2]
       add     r8,r8,r3
       add     r2,r2,#4
       subs    r1,r1,#1
       bgt     ciclo
       mov     r1,#somma
       str     r8,[r1]

