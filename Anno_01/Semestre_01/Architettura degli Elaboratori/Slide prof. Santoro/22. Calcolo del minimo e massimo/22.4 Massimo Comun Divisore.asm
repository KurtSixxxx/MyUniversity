		;		R0 = a
		;		R1 = b
		
		mov		r0,#49
		mov		r1,#21
		
ciclo
		cmp		r0,r1
		beq		fine
		;		cmp		r0,r1
		bgt		maggiore
		
		sub		r1,r1,r0
		b		ciclo
		
maggiore
		sub		r0,r0,r1
		b		ciclo
		
fine
		end
		
