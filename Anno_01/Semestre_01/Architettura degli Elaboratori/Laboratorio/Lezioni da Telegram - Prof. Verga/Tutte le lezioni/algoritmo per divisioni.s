num1      equ     12
num2      equ     4
ris       fill    4

          mov     r1, #num1
          mov     r2, #num2
          mov     r5, #ris
          mov     r0, #0

divisione cmp     r1, r2
          blt     endciclo
          sub     r1, r1, r2
          add     r0, r0, #1
          b       divisione

endciclo  str     r0, [r5]
          end