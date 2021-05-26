
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
		MOV 	$2,-4(%14)
		CMPS 	-4(%14),$3
@if0:
		JNE 	@false0
@true0:
		MOV 	-4(%14),-8(%14)
		JMP 	@exit0
@false0:
		MOV 	$0,-8(%14)
@exit0:
		MOV 	-8(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET