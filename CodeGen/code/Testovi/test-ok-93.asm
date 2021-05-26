
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$0,-4(%14)
		MOV 	$0,%0
		MOV 	$10,%1
@L0:
		CMPU 	%0,%1
		JEQ 	@L_exit
@L1:
		ADDS	%0,$1,%0
		ADDS	-4(%14),$1,%2
		MOV 	%2,-4(%14)
		JMP 	@L0
@L_exit:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET