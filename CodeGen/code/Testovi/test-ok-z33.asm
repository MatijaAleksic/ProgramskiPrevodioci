
y:
		WORD	1
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@main_body:
		MOV 	$2,-4(%14)
		MOV 	$6,y
@if0:
		CMPS 	-4(%14),y
		JNE 	@false0
@true0:
		ADDS	-4(%14),$1,-4(%14)
		MOV 	$2,-4(%14)
		JMP 	@exit0
@false0:
		MOV 	$5,-4(%14)
@exit0:
@if1:
		CMPS 	-4(%14),y
		JGES	@false1
@true1:
		ADDS	y,$1,y
		MOV 	$0,-4(%14)
		JMP 	@exit1
@false1:
@exit1:
		ADDS	-4(%14),y,%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET