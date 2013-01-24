	.file	"main.c"
	.section	".text"
	.align 2
	.globl somme
	.type	somme, @function
somme:
	mr 11,3
	lwz 3,0(3)
	li 9,0
	cmpw 7,9,4
	bgelr- 7
.L6:
	slwi 0,9,2
	lwzx 0,11,0
	cmpw 7,0,3
	ble- 7,.L4
	mr 3,0
.L4:
	addi 9,9,1
	cmpw 7,9,4
	blt+ 7,.L6
	blr
	.size	somme,.-somme
	.align 2
	.globl main
	.type	main, @function
main:
	stwu 1,-48(1)
	mflr 0
	stw 0,52(1)
	addi 3,1,16
	li 4,5
	bl somme
	lwz 0,52(1)
	mtlr 0
	addi 1,1,48
	blr
	.size	main,.-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-9)"
