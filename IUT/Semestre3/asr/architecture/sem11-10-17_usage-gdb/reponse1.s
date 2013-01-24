	.file	"reponse1.c"
	.section	".text"
	.align 2
	.globl distance
	.type	distance, @function
distance:
	subf 0,4,3
	cmpw 7,3,4
	bgt- 7,.L1
	subf 0,3,4
.L1:
	mr 3,0
	blr
	.size	distance,.-distance
	.align 2
	.globl main
	.type	main, @function
main:
	li 3,0
	blr
	.size	main,.-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-9)"
