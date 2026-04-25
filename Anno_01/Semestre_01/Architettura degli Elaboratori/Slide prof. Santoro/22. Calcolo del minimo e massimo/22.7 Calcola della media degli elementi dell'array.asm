		;
dati		dcd		3,4,5,6,7,8,9
		
		mov		r0,#7
		mov		r1,#dati
		mov		r2,#0 	; somma parziale
		
loop
		cmp		r0,#0
		beq		fine_loop
		ldr		r3,[r1]	; elemento i-esimo
		
		add		r2,r2,r3	; aggiornamento somma parziale
		
		add		r1,r1,#4	; incremento puntatore
		sub		r0,r0,#1	; decremento contatore elementi
		b		loop
		
fine_loop
		;		r2 = somma elementi
		;		r0 = 0
		
		mov		r1,r2
		mov		r2,#7
		
		;		r1 = dividendo
		;		r2 = divisore
		;		r0 = quoziente
		
		mov		r0,#0
		
div_loop
		cmp		r1,r2
		blt		div_end
		sub		r1,r1,r2
		add		r0,r0,#1
		b		div_loop
		
div_end
		
		end
		;
		;		int dati[7] = { 3, 4, 5, 6, 7, 8, 9 }
		;		int r1 = dati;
		;		int r0 = 7;
		;		int r2 = 0;
		;		while (r0 > 0) {
		;		int r3 = *r1;
		;		r2 = r2 + r3;
		;		r1++;
		;		r0--;
		;}
		;
