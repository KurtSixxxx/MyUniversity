                      ;
                      ;

vector_v              dcd     32,64,67,43,128,43,64,16,160
vecotr_v_len          dcd     9
sixteen               fill    32


                      ;       r0 ptr a vector_v
                      ;       r1 lunghezza vector_v
                      ;       r2 ptr a sixteen
                      ;       r5 numero elementi in sixteen

                      mov     r0,#vector_v
                      mov     r1,#vecotr_v_len
                      ldr     r1,[r1]
                      mov     r2,#sixteen
                      mov     r5,#0

scan_vector           
                      cmp     r1,#0
                      beq     end_scan_vector

                      ;       r3 elemento corrente
                      ldr     r3,[r0],#4
                      ;       r4 copia per la divisione
                      mov     r4,r3
sixteen_division_loop 
                      cmp     r4,#0
                      ble     end_division

                      sub     r4,r4,#16
                      b       sixteen_division_loop
end_division          

                      cmp     r4,#0
                      blt     dont_store

                      str     r3,[r2],#4
                      add     r5,r5,#1

dont_store            

                      sub     r1,r1,#1
                      b       scan_vector
end_scan_vector       

                      cmp     r5,#1
                      ble     no_mean

                      ;       r0 minimo di sixteen
                      ;       r1 massimo di sixteen
                      ;       r2 ptr a sixteen
                      mov     r0,#0x7FFFFFFF
                      mov     r1,#0x80000000
                      mov     r2,#sixteen

max_min_calc          
                      cmp     r5,#0
                      beq     max_min_calc_end
                      ;       r3 elemento corrente
                      ldr     r3,[r2],#4

                      cmp     r3,r0
                      bgt     not_min
                      mov     r0,r3

not_min               

                      cmp     r3,r1
                      blt     not_max
                      mov     r1,r3

not_max               

                      sub     r5,r5,#1
                      b       max_min_calc
max_min_calc_end      

                      ;       r0 minimo di sixteen
                      ;       r1 massimo di sixteen
                      ;       r2 somma tra r0 e r1
                      ;       r3 quoziente

quoziente_mean        fill    4

                      add     r2,r0,r1
                      mov     r3,#0


calc_mean_loop        
                      cmp     r2,#0
                      beq     end_calc_mean

                      add     r3,r3,#1
                      sub     r2,r2,#2
                      b       calc_mean_loop
end_calc_mean         

                      mov     r4,#quoziente_mean

                      str     r3,[r4]

no_mean               
                      end