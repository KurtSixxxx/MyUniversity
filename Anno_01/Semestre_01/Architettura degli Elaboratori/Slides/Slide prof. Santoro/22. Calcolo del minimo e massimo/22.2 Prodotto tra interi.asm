			mov		r1, #7 ; a = 7
			mov		r2, #20 ; b = 20
			
			mov		r0, #0 ; result = 0
			
loop
			cmp		r2,#0 ; b == 0 ??
			beq		end_program
			
			add		r0,r0,r1 ; r0 = r0 + r1, result = result + a
			sub		r2,r2,#1 ; r2 = r2 - 1, b = b - 1
			
			b		loop
			
end_program
			end
			
