          ;Effettua le due operazioni: 9 + 1 e 9 – 1
          ;e      salvare in memoria il risultato

num_a     dcd     9
num_b     dcd     1
risultato fill    8

          mov     r1, #num_a ;ti prendi prima l'indirizzo
          ldr     r1, [r1] ;e poi il valore contenuto

          mov     r2, #num_b
          ldr     r2, [r2]

          mov     r3, #0 ;faccio una clear e poi addizione
          add     r3, r1, r2

          mov     r4, #0 ;faccio un'altra clear e poi sottrazione
          sub     r4, r1, r2

          mov     r5, #risultato
          str     r3, [r5]
          str     r4, [r5, #4]