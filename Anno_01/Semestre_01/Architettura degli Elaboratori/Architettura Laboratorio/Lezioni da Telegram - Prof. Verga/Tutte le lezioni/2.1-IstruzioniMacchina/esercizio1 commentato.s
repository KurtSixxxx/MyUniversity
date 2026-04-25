          ;       Data la sequenza di numeri 1,2,3,4,5,6,7,8 :
          ;       I. sommare a tutti i numeri la costante 10
          ;       II. sommare i numeri ottenuti
          ;       III. salvare il valore della somma in memoria.

lista     dcd     1,2,3,4,5,6,7,8
dim       dcd     8
costante  equ     10
risultato fill    4

          mov     r1, #dim ;metto in r1 l'indirizzo della dimmensione
          ldr     r1, [r1] ;e qui metto in r1 il valore effettivo della dimenione che è 8
          mov     r2, #lista ;in r2 carico l'indirizzo della lista
          mov     r3, #0 ;qui pulisco r3 che mi serve come accumulatore parziale per le somma

CICLO     ldr     r4, [r2], #4 ;carico in r4 la lista e uso l'offset di 4 byte per iterare su tutta la lista
          add     r4, r4, #costante ;sommo a tutti i numeri la costante (10)
          add     r3, r3, r4 ;pian piano accumulo le somme in r3
          subs    r1, r1, #1 ;sottraggo 1 alla dimensione ad ogni iterazione con subs che aggiorna i flag di stato
          bgt     CICLO ;fine del ciclo (Ossia finchè R1 > 0 che è come dire 8>0)

          ;ora    salviamo il risultato, sovrascriviamo il registro che contiene la dimensione per mettere il risultato
          mov     r1, #risultato
          ldr     r3, [r1]
