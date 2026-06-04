num1            equ     4
num2            equ     3
ris             fill    4

                ;4      x 3
                mov     r1, #num1 ;4
                mov     r2, #num2 ;3
                mov     r5, #ris
                mov     r0, #0

moltiplicazione cmp     r2, #0
                beq     endciclo
                add     r0, r0, r1
                sub     r2, r2, #1
                b       moltiplicazione


endciclo        str     r0, [r5]
                end