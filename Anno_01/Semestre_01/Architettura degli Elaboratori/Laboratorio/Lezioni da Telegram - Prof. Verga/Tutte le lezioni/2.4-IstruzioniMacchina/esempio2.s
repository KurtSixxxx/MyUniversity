lista      dcd     1,2,3,4,5,6,7,8,9,10
dim        equ     10
risultato  fill    4

           mov     r1,#lista
           mov     r2,#dim
           bl      sommatoria
           mov     r1,#risultato
           str     r3,[r1]
           end


sommatoria stmfd   sp!,{r5}
           mov     r3,#0
ciclo      subs    r2,r2,#1
           blt     esci
           ldr     r5,[r1],#4
           add     r3,r3,r5
           b       ciclo
esci       ldmfd   sp!,{r5}
           mov     pc,lr




