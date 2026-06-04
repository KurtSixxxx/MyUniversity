           ;Data   la sequenza di numeri 1,2,3,4,5,6,7,8 :
           ;sommarei numeri di posizione pari.
           ;sottrarre i numeri in posizione dispari
           ;salvarei due risultati in memoria

data       dcd     1,2,3,4,5,6,7,8
result     fill    8
dim        equ     8
           mov     r1,#data
           mov     r2,#result
           mov     r3,#dim
           mov     r4,#0 ;contatore pos pari
           mov     r5,#0 ;contatore pos dis
           mov     r10,#0 ;contatore
clc        subs    r3,r3,#1
           blt     fine
           add     r10,r10,#1
           ldr     r6,[r1],#4 ; pos 1 dispari
           ;verifico se r10 è pari o dispari
           mov     r11,r10
verify     subs    r11,r11,#2
           bgt     verify
           cmp     r11,#0 ;pari
           beq     addPari
           bne     addDispari

addPari    add     r4,r4,r6
           b       clc
addDispari sub     r5,r5,r6
           b       clc

fine       str     r4,[r2]
           str     r5,[r2,#4]