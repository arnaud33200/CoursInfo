	.file	"adist.c"
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
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 2
.LC0:
	.string	"appel distance %d\n"
	.section	".text"
	.align 2
	.globl main
	.type	main, @function
main:
	stwu 1,-16(1)
	mflr 0
	stw 0,20(1)
	li 3,100
	li 4,20
	bl distance
	mr 4,3
	lis 3,.LC0@ha
	la 3,.LC0@l(3)
	crxor 6,6,6
	bl printf
	lwz 0,20(1)
	mtlr 0
	addi 1,1,16
	blr
	.size	main,.-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-9)"
