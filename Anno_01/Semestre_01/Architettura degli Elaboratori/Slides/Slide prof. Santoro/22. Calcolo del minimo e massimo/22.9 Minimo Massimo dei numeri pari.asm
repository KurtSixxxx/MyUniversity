		;
array	dcd		4,9,10,34,8,2,0,4,51,11
		;
		;		r0 = numero di elementi
		;		r1 = puntatore all'elemento corrente
		;		r2 = max
		;		r3 = min
		;		r4 = elemento corrente letto dalla memoria
		;
		mov		r0,#10
		mov		r1,#array
		
		ldr		r2,[r1]
		mov		r3,r2
		
		add		r1,r1,#4
		
loop
		cmp		r0,#1
		beq		end_loop
		
		ldr		r4,[r1]
		
		;;		r4 e' pari???
		
		;		input
		;		r5 = dividendo
		;
		;		output
		;		r6 = quoziente
		;		r5 = resto
		;
		mov		r5,r4
		mov		r6,#0
		
div_loop
		cmp		r5,#2
		blt		div_end
		sub		r5,r5,#2
		add		r6,r6,#1
		b		div_loop
		
div_end
		;		r5 resto
		cmp		r5, #0
		bne		cont2
		
		cmp		r4, r2
		ble		cont
		mov		r2,r4
cont
		
		cmp		r4,r3
		bge		cont2
		mov		r3,r4
cont2
		sub		r0,r0,#1
		add		r1,r1,#4
		b		loop
		
end_loop
		end
		
		
