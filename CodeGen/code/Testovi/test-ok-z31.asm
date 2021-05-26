
y:
		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$2,-4(%14)
		MOV 	$6,y
		ADDS	-4(%14),y,%0
		ADDS	%0,$42,%1
		ADDS	-4(%14),$1,-4(%14)
		ADDS	y,$1,y
		MOV 	%1,y
		ADDS	-4(%14),y,%1
		MOV 	%1,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET