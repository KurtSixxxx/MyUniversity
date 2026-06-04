;	Sia dato un vettore v di interi a 32 bit:
;	
;	1. Generare un nuovo vettore counts il cui i-esimo elemento indica quanti bit
;	a 1 ci sono nell’i-esimo elemento di v (effettuare l’AND con 1 per testare il
;	b0 e poi shiftare a destra il valore, ripetendo queste operazioni per 32 volte);
;
;	2. Determinare il massimo di counts.



vector_v_len    dcd     10
vector_v        dcd     0,1,2,3,4,5,6,7,8,9

counts          fill    40

                ;       r0 = lunghezza di v
                ;       r1 = ptr a v
                ;       r2 = ptr a counts

                mov     r0,#vector_v_len
                ldr     r0,[r0]
                mov     r1,#vector_v
                mov     r2,#counts



scan_v_loop     
                cmp     r0,#0
                beq     end_scan_v

                ;       r3 = elemento corrente
                ;       r4 = bit corrente
                ;       r5 = contatore
                ;       r6 = risultato and
                ldr     r3,[r1],#4
                mov     r4, #0
                mov     r5,#0
count_bits_loop 
                cmp     r4,#32
                beq     end_count_bits

                and     r6,r3,#1
                cmp     r6,#1
                bne     bit_zero

                add     r5,r5,#1

bit_zero        

                lsr     r3,r3,#1
                add     r4,r4,#1
                b       count_bits_loop
end_count_bits  
                str     r5,[r2],#4
                sub     r0,r0,#1
                b       scan_v_loop
end_scan_v      
                ;       r0 = lunghezza di counts (= v)
                ;       r1 = ptr a counts
                ;       r2 = counts max

                mov     r0,#vector_v_len
                ldr     r0,[r0]
                mov     r1,#counts
                mov     r2,#0x80000000

search_max      
                cmp     r0,#0
                beq     end_search
                ;       r3 = elemento corrente
                ldr     r3,[r1],#4

                cmp     r3,r2
                ble     not_greater

                mov     r2,r3

not_greater     

                sub     r0,r0,#1
                b       search_max
end_search      
				end
