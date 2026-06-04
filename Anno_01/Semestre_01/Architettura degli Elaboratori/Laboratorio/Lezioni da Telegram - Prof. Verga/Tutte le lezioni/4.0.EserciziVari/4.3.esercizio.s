          ;Eseguire la divisione 274 / 13
          ;e      salvare il risultato e il resto

fattore1  dcd     274
fattore2  dcd     13
risultato fill    4
resto     fill    4

          mov     r1,#fattore1
          ldr     r1,[r1]
          mov     r2,#fattore2
          ldr     r2,[r2]

          mov     r7,#0 ; contatore

          mov     r8,#risultato
          mov     r9,#resto
ciclo     cmp     r1,r2
          blt     fine
          sub     r1,r1,r2
          add     r7,r7,#1
          b       ciclo

fine      str     r1,[r9]
          str     r7,[r8]