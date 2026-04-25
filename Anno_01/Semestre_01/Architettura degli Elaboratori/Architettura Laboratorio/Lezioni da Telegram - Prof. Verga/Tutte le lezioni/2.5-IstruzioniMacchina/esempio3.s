          ;       dividere i valori 9 e 3

costante1 equ     9
costante2 equ     3

          mov     r1,#costante1
          mov     r2,#costante2
          mov     r3,#0
ciclo     cmp     r1,r2
          blt     esci
          add     r3,r3,#1 ;risultato
          subs    r1,r1,r2
          b       ciclo
          ;       r1 resto
esci      end
