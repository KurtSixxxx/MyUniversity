

vector_v_len   dcd     5
vector_v       dcd     1,2,3,4,8

zero_len       dcd     0
zero           fill    20

one_len        dcd     0
one            fill    20

two_len        dcd     0
two            fill    20

three_len      dcd     0
three          fill    20

               ;       r0 ptr a zero
               ;       r1 ptr a one
               ;       r2 ptr a two
               ;       r3 ptr a three
               ;       r4 v length
               ;       r5 ptr a v

               mov     r0,#zero
               mov     r1,#one
               mov     r2,#two
               mov     r3,#three

               mov     r4,#vector_v_len
               ldr     r4,[r4]
               mov     r5,#vector_v

scan_v_loop    
               cmp     r4,#0
               beq     end_v_scan

               ;       r6 elemento corrente
               ;       r7 copia
               ;       r8 and operation result
               ;       r9 bit corrente
               ldr     r6,[r5],#4
               mov     r7,r6
               mov     r9,#0

scan_bits_loop 
               cmp     r9,#4
               beq     end_bit_scan

               and     r8,r7,#1
               lsr     r7,r7,#1
               cmp     r8,#1
               bne     dont_store

               bl      store_value

dont_store     

               add     r9,r9,#1
               b       scan_bits_loop
end_bit_scan   


               sub     r4,r4,#1
               b       scan_v_loop
end_v_scan     

               end

store_value    
               ;       input:
               ;       r6 = elemento da salvare
               ;       r9 = bit corrente
               cmp     r9,#0
               bne     not_zero
               mov     r10,r0
               add     r0,r0,#4
               mov     r11,#zero_len
               b       skip
               ;       r10 = ptr at store location
               ;       r11 = ptr at store length
not_zero       

               cmp     r9,#1
               bne     not_one

               mov     r10,r1
               add     r1,r1,#4
               mov     r11,#one_len
               b       skip

not_one        

               cmp     r9,#2
               bne     not_two

               mov     r10,r2
               add     r2,r2,#4
               mov     r11,#two_len
               b       skip

not_two        

               cmp     r9,#3
               bne     not_three

               mov     r10,r3
               add     r3,r3,#4
               mov     r11,#three_len

not_three      

skip           

               str     r6,[r10]
               ldr     r10,[r11]
               add     r10,r10,#1
               str     r10,[r11]

               mov     pc,lr