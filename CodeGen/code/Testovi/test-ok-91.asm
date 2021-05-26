
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$5,-4(%14)
		JMP	@L0
@L0:
		CMPS 	-4(%14),$8
		JGES	@L_exit
@L1:
		ADDS	-4(%14),$1,-4(%14)
		JMP 	@L0
@L_exit:
		MOV 	-4(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET