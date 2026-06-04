



;;; for (int i = 0; i < 10; i++) {
;;; ....
;;; }

;;; i = 0;
;;; loop:
;;;    if (i >= 10) goto end_loop;
;;;    ....
;;;    i = i + 1;
;;;    goto loop;
;;;
;;; end_loop:
;;;

	mov r1,#0

loop
	cmp r1,#10
	bge end_loop
	...
	...
	...
	add r1,r1,#1
	b loop

end_loop


;;;

	mov r1,#10

loop
	cmp r1,#0
	beq end_loop
	...
	...
	...
	sub r1,r1,#1
	b loop
end_loop


;;;
;;;    if (a & 1 == 0) {
;;;       then_part
;;;    }
;;;    else {
;;;       else_part
;;;    }

;;; a = R0
;;;
        and r2, r0, #1
        cmp r2,#0
        bne else_part
 ;;; then_part
        ....
	   b cont
else_part
	   ....

cont
	...

		