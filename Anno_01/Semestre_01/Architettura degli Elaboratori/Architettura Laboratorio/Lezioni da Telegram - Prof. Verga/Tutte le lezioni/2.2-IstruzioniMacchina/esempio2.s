          ;Data   la lista 1,24,12,8,10,1,4,21,3,1,5,1
          ;trovareil valore 10 in memoria
          ;e      salvare in memoria l’indirizzo corrispondente.
          ;Se     non viene trovato salvare -1.

lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim       dcd     12
costante  equ     10
risultato fill    4
          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#lista
ciclo     ldr     r3,[r2]
          cmp     r3,#costante
          beq     found
          add    r2,r2,#4
          subs    r1,r1,#1
          bgt     ciclo
          ;mov    r9,#-1
          ;mov    r10,#risultato
          ;str    r9,[r10]
          ;end
          mov     r2,#-1
found     mov     r10,#risultato
          str     r2,[r10]

