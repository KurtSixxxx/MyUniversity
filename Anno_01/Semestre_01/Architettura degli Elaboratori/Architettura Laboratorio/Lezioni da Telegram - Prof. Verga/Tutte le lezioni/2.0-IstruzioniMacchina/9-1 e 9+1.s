          ;Effettua le due operazioni: 9 + 1 e 9 – 1
          ;e      salvare in memoria il risultato

num_a     equ     9
num_b     equ     1
risultato fill    8
          ;somma
          mov     r1,#num_a
          mov     r2,#num_b
          add     r3,r1,r2
          ;sottrazione
          sub     r4,r1,r2
          mov     r6,#risultato
          str     r3,[r6]
          str     r4,[r6,#4]
