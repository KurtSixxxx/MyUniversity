          ;Data   la lista;
          ;1,24,12,8,10,1,4,21,3,1,5,1
          ;trovareil valore 10 in memoria e salvare in memoria l’indirizzo corrispondente. Se non viene trovato salvare -1.

LISTA     DCD     1,24,12,8,10,1,4,21,3,1,5,1
DIM       DCD     12
SEARCH    EQU     10
RISULTATO FILL    4

          MOV     R1, #LISTA ;R1 ora contiene l'indirizzo della lista
          MOV     R2, #DIM ;R2 ora contiene l'indirizzo della dimensione
          LDR     R2, [R2] ;R2 ora contiene il valore della dimensione (Ossia 12)
          MOV     R3, R1 ;R3 ora contiene una copia dell'indirizzo della lista, che chiamiamo indirizzo base, per poi trovare l'indirizzo(offset)

CICLO     LDR     R4, [R1] ;Carichiamo il valore attuale in R4
          CMP     R4, #SEARCH ;Compariamo il valore attuale in R4 con 10, ossia il valore da trovare
          BEQ     FIND ;Se sono EQUAL (uguali) allora rimandiamo alla parte di programma "FIND"
          ADD     R1, R1, #4 ;Se siamo qui non è stato trovato 10, si passa con #4 (spostandoci con i byte di 4 a 4)
          SUBS    R2, R2, #1 ;Sottraiamo 1 al contatore, una volta che non sarà più 12 (quindi 0) vorrà dire che abbiamo iterato su tutti i valori della lista
BGT       CICLO   ;Questo BGT fa riferimento alla riga sopra (SUBS) ossia, quando R2 = 0 usciamo dal ciclo. Se R2 > 0 allora si ripete.


          ;Se     il valore non è stato trovato:

          MOV     R4, #-1
          MOV     R0, #RISULTATO
          STR     R4, [R0]
BGT       END

          ;FIND   è la sequenza di istruzioni da utilizzare quando abbiamo trovato il valore
          ;A      questo punto utilizziamo una formula per trovare e salvare in memoria l’indirizzo corrispondente al valore 10
          ;R4     = 10, il valore trovato
          ;La     formula è R1 - R3, ossia ---> Calcola offset (indirizzo corrente - base)

FIND      SUB     R4, R1, R3
          MOV     R0, #RISULTATO ;Spostiamo l'indirizzo di #RISULTATO in r0
          STR     R4, [R0] ;Salviamo il valore di R4 in R0