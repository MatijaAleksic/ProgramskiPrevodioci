
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$1,-4(%14)
		MOV 	$1,-8(%14)
		JMP	@L0
@L0:
		CMPS 	-4(%14),$10
		JGES	@L_exit
@L1:
		ADDS	-4(%14),$1,-4(%14)
		JMP 	@L0
@L_exit:
		ADDS	-4(%14),-8(%14),%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET