          ;       Data la sequenza di numeri 1,2,3,4,5,6,7,8 :
          ;I.     sommare a tutti i numeri la costante 10; fatto
          ;II.    sommare i numeri ottenuti;
          ;III.   salvare il valore della somma in memoria. quasi

num       dcd     1,2,3,4,5,6,7,8
costante  equ     10
dim       equ     8
risultato fill    4

          ;mettiamo in r1 sia indirizzo che contenuto
          mov     r1, #num
          mov     r0, #dim
          mov     r6, #0
          mov     r5, #risultato



ciclo     cmp     r0, #0
          beq     endciclo

          ldr     r2, [r1], #4
          add     r2, r2, #10
          add     r6, r6, r2
          sub     r0, r0, #1 ;sottrazione per diminuire numero iterazioni da 8 a 0
          b       ciclo

          ;sumloopcmp r0, #0


endciclo  str     r2, [r5]
          end