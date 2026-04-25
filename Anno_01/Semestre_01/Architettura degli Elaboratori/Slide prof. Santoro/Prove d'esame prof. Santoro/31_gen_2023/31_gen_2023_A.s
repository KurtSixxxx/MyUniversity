
v_length    dcd     10
vector_v    dcd     1,2,3,4,5,6,7,8,9,10

evens_len   fill    4
evens       fill    40
odds_len    fill    4
odds        fill    40

            ;       r0 lunghezza v
            ;       r1 ptr a vector_v
            ;       r2 ptr a evens
            ;       r3 ptr a odds
            ;       r6 lunghezza evens
            ;       r7 lunghezza odds

            mov     r0,#v_length
            ldr     r0,[r0]
            mov     r1,#vector_v
            mov     r2,#evens
            mov     r3,#odds
            mov     r6,#0
            mov     r7,#0

scan_v_loop 
            cmp     r0,#0
            beq     end_scan

            ;       r4 elemento corrente
            ;       r5 copia e risultato and logico
            ldr     r4,[r1],#4
            mov     r5,r4

            and     r5,r5,#1

            cmp     r5,#0
            bne     store_odds

            str     r4,[r2],#4
            add     r6,r6,#1
            b       is_even

store_odds  
            str     r4,[r3],#4
            add     r7,r7,#1
is_even     

            sub     r0,r0,#1
            b       scan_v_loop
end_scan    

            mov     r0,#odds_len
            str     r7,[r0]

            mov     r0,#evens_len
            str     r6,[r0]