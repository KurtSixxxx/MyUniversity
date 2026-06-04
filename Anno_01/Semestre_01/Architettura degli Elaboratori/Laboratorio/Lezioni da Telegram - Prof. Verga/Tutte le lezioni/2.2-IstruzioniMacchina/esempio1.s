          ;Supponiamo che tre studenti abbiamo eseguito
          ;3      prove ognuna con voto da 18 a 30.
          ;Sommarei voti ottenuti dagli studenti per
          ;ogni   prova e salvare il risultato in memoria.
          ;Lista: 1,20,20,20, 2,18,30,27, 3,22,26,28

lista     dcd     1,20,20,20,2,18,30,27,3,22,26,28
dim       equ     3
risultati fill    12

          mov     r1,#dim
          mov     r2,#lista
          mov     r3,#0 ;somma voto 1
          mov     r4,#0 ;somma voto 2
          mov     r5,#0 ;somma voto 3
ciclo     add     r2,r2,#4
          ldr     r6,[r2],#4
          add     r3,r3,r6
          ;add     r2,r2,#4
          ldr     r6,[r2],#4
          add     r4,r4,r6
          ;add     r2,r2,#4
          ldr     r6,[r2],#4
          add     r5,r5,r6
          ;add     r2,r2,#4
          subs    r1,r1,#1
          bgt     ciclo
          mov     r1,#risultati
          str     r3,[r1]
          str     r4,[r1,#4]
          str     r5,[r1,#8]


