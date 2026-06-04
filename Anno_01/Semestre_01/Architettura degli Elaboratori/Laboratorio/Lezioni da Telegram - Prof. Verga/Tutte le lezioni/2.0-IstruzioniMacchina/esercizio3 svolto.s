          ;Sommarei numeri 2,3,4,1 e salvare
          ;in     memoria il risultato

num1      dcd     2
num2      dcd     3
num3      dcd     4
num4      dcd     1
risultato fill    4

          mov     r1, #num1 ; Carica l'indirizzo di num1 in r1
          ldr     r1, [r1] ; Carica il valore di num1 in r1

          mov     r2, #num2
          ldr     r2, [r2]

          mov     r3, #num3
          ldr     r3, [r3]

          mov     r4, #num4
          ldr     r4, [r4]

          mov     r5, #0
          add     r5, r1, r2
          add     r5, r5, r3
          add     r5, r5, r4

          mov r6, #risultato  ; Carica in r6 l'indirizzo della variabile risultato
          str r5, [r6]        ; Salva 10 all'indirizzo di risultato
          
          ldr r6, [r6]        ; Ora r6 conterrà il valore 10
