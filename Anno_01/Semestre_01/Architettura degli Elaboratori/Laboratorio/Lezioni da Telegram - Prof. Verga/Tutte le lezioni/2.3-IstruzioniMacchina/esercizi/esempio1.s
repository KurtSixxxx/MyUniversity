               ;Data   la lista
               ;1,24,12,8,10,1,4,21,3,1,5,1
               ;trovareil valore 10 in memoria e
               ;salvarein memoria l’indirizzo corrispondente.
               ;Se     non viene trovato salvare -1.

lista          dcd     1,24,12,8,1,1,4,21,3,1,5,1
dim            equ     12
costante       equ     10
risultato      fill    4

               mov     r1,#lista
               mov     r2,#dim ;10
               mov     r3,#risultato
ciclo          ldr     r4,[r1]
               cmp     r4,#costante
               beq     salvaindirizzo
               add     r1,r1,#4
               subs    r2,r2,#1
               bgt     ciclo
               mov     r1,#-1
               ;str    r7,[r3]
               ;end
salvaindirizzo str     r1,[r3]
               end


