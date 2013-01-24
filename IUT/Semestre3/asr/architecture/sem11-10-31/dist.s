	.file	"dist.c"
	.section	".text"
	.align 2
	.globl distance
	.type	distance, @function
distance:
#APP
	subf 0,4,3
	cmpw 7,3,4
	bgt- 7,.L1
	subf 0,3,4
	.L1:
	mr 3,0
	blr
#NO_APP
	blr
	.size	distance,.-distance
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-9)"
