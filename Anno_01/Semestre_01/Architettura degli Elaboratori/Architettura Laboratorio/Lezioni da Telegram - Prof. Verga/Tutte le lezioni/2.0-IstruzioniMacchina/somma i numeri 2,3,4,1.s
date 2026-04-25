          ;Sommare i numeri 2,3,4,1 e salvare
          ;in     memoria il risultato

num_a     dcd     2
num_b     dcd     3
num_c     dcd     4
num_d     dcd     1
risultato fill    4
          ;leggiamo i dati
          mov     r1,#num_a
          ldr     r1,[r1]
          mov     r2,#num_b
          ldr     r2,[r2]
          mov     r3,#num_c
          ldr     r3,[r3]
          mov     r4,#num_d
          ldr     r4,[r4]
          ;sommo  i dati
          mov     r5,#0 ;clear
          add     r5,r5,r1
          add     r5,r5,r2
          add     r5,r5,r3
          add     r5,r5,r4
          ;salvo  il risultato in memoria
          mov     r6,#risultato
          str     r5,[r6]


