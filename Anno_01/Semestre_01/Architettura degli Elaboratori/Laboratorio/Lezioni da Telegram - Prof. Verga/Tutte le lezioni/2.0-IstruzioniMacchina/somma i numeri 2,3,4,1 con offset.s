          ;Sommare i numeri 2,3,4,1 e salvare
          ;in     memoria il risultato

num       dcd     2,3,4,1 ;Dichiara una variabile 'num' contenente i valori 2,3,4,1 in memoria
risultato fill    4 ;Riserva 4 byte in memoria per il risultato (utile per salvataggio)

          mov     r1,#num ;Carica l'indirizzo base di 'num' in r1
          ldr     r2,[r1] ;Carica il primo valore (2) in r2
          add     r1,r1,#4 ;Sposta l'indirizzo di r1 al prossimo elemento (3)
          ldr     r3,[r1] ;Carica il secondo valore (3) in r3
          add     r1,r1,#4 ;Sposta l'indirizzo di r1 al prossimo elemento (4)
          ldr     r4,[r1] ;Carica il terzo valore (4) in r4
          add     r1,r1,#4 ;Sposta l'indirizzo di r1 all'ultimo elemento (1)
          ldr     r5,[r1] ;Carica l'ultimo valore (1) in r5

          ;mov    r9,#0
          ;Somma progressiva dei valori in r9
          add     r9,r2,r3
          add     r9,r9,r4
          add     r9,r9,r5

          mov     r1,#risultato ;Carica l'indirizzo di 'risultato' in r1
          str     r9,[r1] ;Salva il risultato finale (10) nell'indirizzo di 'risultato'