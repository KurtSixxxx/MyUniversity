		
dati		dcd		3,4,5,6
		
		mov		r1,#dati
		ldr		r2,[r1]
		
		add		r1,r1,#4
		ldr		r3,[r1]
		
		add		r1,r1,#4
		ldr		r4,[r1]
		
		add		r1,r1,#4
		ldr		r5,[r1]
		
		add		r2,r2,#10
		add		r3,r3,#10
		add		r4,r4,#10
		add		r5,r5,#10
		
		str		r5,[r1]
		sub		r1,r1,#4
		str		r4,[r1]
		sub		r1,r1,#4
		str		r3,[r1]
		sub		r1,r1,#4
		str		r2,[r1]
		
		
		end
		
