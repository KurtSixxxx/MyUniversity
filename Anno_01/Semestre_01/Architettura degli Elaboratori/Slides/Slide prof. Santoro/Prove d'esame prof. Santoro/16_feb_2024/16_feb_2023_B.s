b_len              dcd     13
array_b            dcd     1,2,3,4,5,6,7,8,9,10,11,23,65
a_len              dcd     10
array_a            dcd     1,2,3,4,5,6,7,8,9,65
a_extra            fill    52


                   ;       r0 lunghezza b
                   ;       r1 ptr a b
                   ;       r4 ptr alla fine di a
                   ;       r7 lunghezza di a finale
                   mov     r0,#b_len
                   ldr     r0,[r0]
                   mov     r1,#array_b
                   mov     r4,#a_extra
                   mov     r7,#a_len
                   ldr     r7,[r7]
scan_b_loop        
                   cmp     r0,#0
                   beq     end_scan_b

                   ;       r5 elemento corrente b
                   ;       r2 lunghezza a iniziale
                   ;       r3 ptr ad a
                   ldr     r5,[r1],#4
                   mov     r2,#a_len
                   ldr     r2,[r2]
                   mov     r3,#array_a


scan_a_loop        
                   ;       r6 elemento corrente a
                   ldr     r6,[r3],#4
                   cmp     r5,r6
                   beq     dont_store_element

                   cmp     r2,#0
                   beq     store_element

                   sub     r2,r2,#1

                   b       scan_a_loop
store_element      
                   str     r5,[r4],#4
                   add     r7,r7,#1
dont_store_element 
                   sub     r0,r0,#1
                   b       scan_b_loop
end_scan_b         


                   ;       r2 lunghezza a (aggiornata)
                   ;       r3 ptr ad a
                   ;       r0 = minimo
                   mov     r2,#a_len
                   str     r7,[r2]
                   ldr     r2,[r2]
                   mov     r3,#array_a
                   ldr     r0,[r3],#4
                   sub     r2,r2,#1
search_min_loop    
                   cmp     r2,#0
                   beq     end_search
                   ;       r1 elemento corrente di a
                   ldr     r1,[r3],#4

                   cmp     r1,r0
                   bge     not_min

                   mov     r0,r1

not_min            

                   sub     r2,r2,#1
                   b       search_min_loop
end_search         