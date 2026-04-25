;somma di lista di numeri e salvataggio in memoria

num       dcd     2,3,4,1 ;ho caricato l'array
risultato fill    4 ;ho preservato spazio per risultato

          mov     r0, #num ;ho messo la variabile numeri in r0
          mov     r1, #risultato ;ho messo la variabile risultato in r1
          mov     r2, #0 ;ho fatto la clear per l'accumulatore

          ldr     r3, [r0] ;carico l'indirizzo del primo numero
          add     r2, r2, r3 ;somma con 2

          ldr     r3, [r0, #4] ;ho caricato in r3 l'indirizzo di (3) con offset
          add     r2, r2, r3 ;somma con 3

          ldr     r3, [r0, #8] ;ho caricato in r3 l'indirizzo di (4) con offset
          add     r2, r2, r3 ;somma con 4

          ldr     r3, [r0, #12] ;ho caricato in r3 l'indirizzo di (1) con offset
          add     r2, r2, r3 ;somma con 1

          str     r2, [r1] ;sposto il risultato nell'indirizzo in cui c'è #risultato