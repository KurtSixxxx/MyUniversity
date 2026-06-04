
vector_v_len dcd     5
vector_v     dcd     136,32,16,137,140

vector_v1    fill    20

             ;       r0 lunghezza v
             ;       r1 ptr a v
             ;       r2 ptr a v1

             mov     r0,#vector_v_len
             ldr     r0,[r0]
             mov     r1,#vector_v
             mov     r2,#vector_v1

scan_v_loop  
             cmp     r0,#0
             beq     end_scan_v

             ;       r3 = elemento corrente
             ;       r4 = check
             ;       r5 = loop counter
             ;       r6 = copia di r3
             ldr     r3,[r1],#4
             mov     r4,#0
             mov     r5,#32
             mov     r6,r3

             lsr     r6,r6,#3
             and     r7,r6,#1
             cmp     r7,#1
             bne     bit_3_zero
             add     r4,r4,#1
bit_3_zero   
             lsr     r6,r6,#4
             and     r7,r6,#1
             cmp     r7,#1
             bne     bit_7_zero
             add     r4,r4,#1
bit_7_zero   
             cmp     r4,#2
             bne     dont_store
             str     r3,[r2],#4
dont_store   

             sub     r0,r0,#1
             b       scan_v_loop
end_scan_v   