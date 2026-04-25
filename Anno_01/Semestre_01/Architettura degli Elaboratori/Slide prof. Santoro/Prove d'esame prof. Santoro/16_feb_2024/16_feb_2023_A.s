                    ;
                    ;
                    ;
a_lenght            dcd     11
array_a             dcd     1,43,23,54,43,98,21,23,23,98,1
b_lenght            dcd     4
array_b             dcd     43,23,1,98

occurences          fill    16

                    ;       r0 b lenght
                    ;       r1 pointer to b
                    ;       r2 pointer to occurences

                    mov     r0,#b_lenght
                    ldr     r0, [r0]
                    mov     r1,#array_b
                    mov     r2,#occurences


scan_b_loop         
                    cmp     r0,#0
                    beq     end_scan_b

                    ;       r3 current element
                    ldr     r3,[r1],#4
                    bl      count_occurences
                    str     r7,[r2],#4
                    sub     r0,r0,#1
                    b       scan_b_loop
end_scan_b          
                    ;       r0 occurences lenght (= b_lenght)
                    ;       r1 occurences pointer
                    ;       r2 max element
                    mov     r0,#b_lenght
                    ldr     r0, [r0]
                    mov     r1,#occurences
                    mov     r2,#0x80000000

calc_occurences_max 
                    cmp     r0,#0
                    beq     end_calc_loop

                    ;       r3 current element
                    ldr     r3,[r1],#4

                    cmp     r3,r2
                    blt     not_greater
                    mov     r2,r3
not_greater         

                    sub     r0,r0,#1
                    b       calc_occurences_max
end_calc_loop       
                    end

                    ;subroutine
                    ;input  r3
count_occurences    
                    ;       r4 a lenght
                    ;       r5 pointer to a
                    mov     r4,#a_lenght
                    ldr     r4, [r4]
                    mov     r5,#array_a
                    ;       r7 output (counter)
                    mov     r7,#0

scan_a_loop         
                    cmp     r4,#0
                    beq     end_scan_a

                    ;r6     current a element
                    ldr     r6,[r5],#4

                    cmp     r6,r3
                    bne     dont_increase
                    add     r7,r7,#1
dont_increase       

                    sub     r4,r4,#1
                    b       scan_a_loop
end_scan_a          
                    mov     pc,lr