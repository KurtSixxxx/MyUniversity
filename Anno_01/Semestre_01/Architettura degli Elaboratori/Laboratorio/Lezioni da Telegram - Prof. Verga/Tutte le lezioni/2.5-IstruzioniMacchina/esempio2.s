          ;       moltiplicare 9 x 3

costante1 equ     9
costante2 equ     3

          mov     r1,#costante1
          mov     r2,#costante2
          mov     r3,#0
ciclo     subs    r2,r2,#1
          blt     esci
          add     r3,r3,#costante1
          b       ciclo

esci      end
