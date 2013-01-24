	.file	"moins.c"
	.section	".text"
	.align 2
	.globl moins
	.type	moins, @function
moins:
	srawi 3,3,1
	addze 3,3
	blr
	.size	moins,.-moins
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-9)"
