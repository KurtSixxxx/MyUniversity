
v_len           dcd     8
v_vector        dcd     3,45,31,75,32,87,4,9

evens           fill    32
odds            fill    32

                ;       r1 v pointer
                ;       r2 array lenght
                ;       r3 evens pointer
                ;       r4 odds pointer

                mov     r2,#v_len
                ldr     r2,[r2]
                mov     r0,r2

                mov     r1,#v_vector

                mov     r3,#evens
                mov     r4,#odds

vector_scan     
                cmp     r2,#0
                beq     end_scan

                ;       r5 buffer

                ldr     r5,[r1],#4

                cmp     r2,r0
                beq     even_index

                str     r5,[r4],#4

                b       skip

even_index      

                str     r5,[r3],#4
                sub     r0,r0,#2

skip            

                sub     r2,r2,#1
                b       vector_scan
end_scan        

                ;       r5 evens max
                ;       r6 evens min
                ;       r7 odds max
                ;       r8 odds min

scan_values     




end_values_scan 


                end