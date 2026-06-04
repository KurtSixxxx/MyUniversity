          ;Data   la lista
          ;1,24,12,8,10,1,4,21,3,1,5,1
          ;contareil numero di volte che compare in memoria il valore 1 e salvare il risultato in memoria.

arr       dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim       dcd     12
tag       equ     1
risultato fill    4

          mov     r1, #arr ;mi carico l'indirizzo dell'arr in r1
          mov     r2, #dim ;carico l'indirizzo della dimensione dell'arr
          ldr     r2, [r2] ;carico il valore della dimensione
          mov     r3, #0 ;faccio la clear del registro accumulatore

          ;apro   il ciclo per trovare le occorenze di 1

ciclo     ldr     r4, [r1] ;carico il primo numero
          cmp     r4, #tag ;confronto il numero e 1
          bne     next ;se sono diversi passa al prossimo numero
          add     r3, r3, #1 ;se sono uguali aggiungo 1 al contatore

next      add     r1, r1, #4 ;mi sposto nell'arr
          subs    r2, r2, #1 ;diminisco il contatore DIM
          bgt     ciclo ;concludo il ciclo quando R2 == 0

          mov     r0, #risultato ;metto l'indirizzo di risultato in r0
          str     r3, [r0] ;e quallo che in r3 lo metto in r0