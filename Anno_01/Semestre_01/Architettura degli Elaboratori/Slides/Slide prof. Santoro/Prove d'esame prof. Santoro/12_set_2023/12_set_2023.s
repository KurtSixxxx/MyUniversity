
vector_v_len  dcd     10
vector_v      dcd     1,2,3,4,6,7,8,9,10,12
int_k         dcd     3

a1            fill    40
a2            fill    40


              ;       r1 a1 pointer
              ;       r2 a2 poiner
              ;       r3 v length
              ;       r4 v pointer
              ;       r7 a1 len
              ;       r8 a2 len


              mov     r1,#a1
              mov     r2,#a2
              mov     r3,#vector_v_len
              ldr     r3,[r3]
              mov     r4,#vector_v
              mov     r5,#int_k
              ldr     r5,[r5]

              mov     r7,#0
              mov     r8,#0


scan_v_loop   
              cmp     r3,#0
              beq     end_scan

              ;       r0 elemento corrente
              ;       r5 int k
              ;       r6 copia r0
              ldr     r0,[r4],#4
              mov     r6,r0



division_loop 
              cmp     r6,#0
              ble     end_division

              sub     r6,r6,r5
              b       division_loop
end_division  

              cmp     r6,#0
              blt     store_a2
              str     r0,[r1],#4
              add     r7,r7,#1
              b       skip

store_a2      
              str     r0,[r2],#4
              add     r8,r8,#1
skip          
              sub     r3,r3,#1
              b       scan_v_loop
end_scan      

              mov     r0,#2

              cmp     r8,r7
              bgt     a2_bigger

              mov     r0,#1

a2_bigger     

              end
