	.file	"foo.c"
	.section	".text"
	.align 2
	.globl foo
	.type	foo, @function
foo:
	li 9,0
.L5:
	addi 3,3,1
	addi 9,9,1
	cmpwi 7,9,4
	ble+ 7,.L5
	add 3,3,4
	blr
	.size	foo,.-foo
	.align 2
	.globl main
	.type	main, @function
main:
	stwu 1,-16(1)
	mflr 0
	stw 0,20(1)
	li 3,20
	li 4,5
	bl foo
	li 3,0
	lwz 0,20(1)
	mtlr 0
	addi 1,1,16
	blr
	.size	main,.-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-9)"
