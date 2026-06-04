; somma 3 numeri e salva il risultato in memoria

num1 dcd 4 ;attribuisco 4 a num1
num2 dcd 8 ;attribuisco 8 a num2
num3 dcd 12 ;attribuisco 12 a num2
risultato fill 4 ;alloco 4 byte per il risultato, mi servirà per la store

mov r1, #num1 ;sposto 4 in r1
mov r2, #num2 ;sposto 8 in r2
mov r3, #num3  ;sposto 12 in r3

add r1, r1, r2 ; sommo 4 e 8
add r1, r1, r3 ; sommo 12 e 12 = 24 i r1

mov r4, #risultato ; carica l'indirizxo di risultato i r4
str r1, [r4] ; salva il risultato all'indirizzo puntato da r4