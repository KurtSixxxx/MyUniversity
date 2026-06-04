		
		; input
		; r1 = dividendo
		; r2 = divisore
		;
		; output
		; r0 = quoziente
		; r1 = resto
		;
		mov		r1,#49
		mov		r2,#7

		
		mov		r0,#0
		
div_loop
		cmp		r1,r2
		blt		div_end
		sub		r1,r1,r2
		add		r0,r0,#1
		b		div_loop
		
div_end
		end
		
