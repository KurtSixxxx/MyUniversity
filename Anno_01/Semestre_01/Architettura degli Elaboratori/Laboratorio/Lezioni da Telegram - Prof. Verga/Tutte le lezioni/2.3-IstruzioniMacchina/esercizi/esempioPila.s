          ;Eseguire l'operazione 20 + 10 - 15
          ;e      salvare il risultato in memoria,
          ;usando la pila e conservando i vecchi valori
          ;contenuti nei registri.

NA        equ     20
NB        equ     10
NC        equ     15
risultato fill    4

          mov     r1,#12
          mov     r2,#10
          mov     r3,#1
          mov     r4,#40

          STMFD   sp!, {r1,r2,r3,r4,r5,r6,r7,r8}
          mov     r1,#20
          mov     r2,#NB
          mov     r3,#NC
          mov     r4,#0
          add     r4,r4,r1
          add     r4,r4,r2 ;20 + 10
          ;add    r4,r1,r2
          sub     r4,r4,r3 ; 30 - 15
          mov     r5,#risultato
          str     r4,[r5]
          LDMFD   SP!,{r1,r2,r3,r4,r5,r6,r7,r8}






