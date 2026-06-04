lista  dcd     1,2,34
       mov     r1,#11
       mov     r2,#-1
       and     r3,r1,r2
       orr     r4,r1,r2
       eor     r5,r1,r2
       lsl     r6,r2,#2
       lsr     r7,r2,#2
       asr     r8,r2,#2
       ror     r9,r1,#6
       mov     r1,#lista
       ldrb    r3,[r1,#0]
       ldrb    r4,[r1,#1]
       strb    r6,[r1,#2]