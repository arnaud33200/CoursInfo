	.file	"plus.c"
	.section	".text"
	.align 2
	.globl plus
	.type	plus, @function
plus:
	addi 3,3,1
	blr
	.size	plus,.-plus
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-9)"
