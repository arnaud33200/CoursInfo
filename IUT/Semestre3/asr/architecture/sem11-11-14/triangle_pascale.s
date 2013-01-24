	.file	"triangle_pascale.c"
	.section	".text"
	.align 2
	.globl triangle
	.type	triangle, @function
triangle:
	li 0,1
	cmpwi 7,5,1
	beq- 7,.L1
	li 10,0
	cmpw 7,10,5
	bge- 7,.L16
	slwi 11,10,2
	li 9,0
.L6:
	addi 5,5,1
	cmpw 7,10,5
	blt+ 7,.L6
	stwx 9,11,3
.L16:
	li 0,1
	stw 0,0(3)
	stw 0,4(3)
	li 8,0
	cmpw 7,8,6
	bge- 7,.L18
.L14:
	li 10,1
	cmpw 7,10,5
	bge- 7,.L20
.L13:
	slwi 11,10,2
	add 9,11,3
	lwz 0,-4(9)
	lwzx 9,11,3
	add 0,0,9
	stwx 0,11,4
	addi 10,10,1
	cmpw 7,10,5
	blt+ 7,.L13
.L20:
	mr 0,3
	mr 3,4
	mr 4,0
	addi 8,8,1
	cmpw 7,8,6
	blt+ 7,.L14
.L18:
	slwi 0,5,2
	lwzx 0,3,0
.L1:
	mr 3,0
	blr
	.size	triangle,.-triangle
	.align 2
	.globl main
	.type	main, @function
main:
	stwu 1,-80(1)
	mflr 0
	stw 0,84(1)
	addi 3,1,16
	addi 4,1,48
	li 5,3
	li 6,4
	bl triangle
	li 3,0
	lwz 0,84(1)
	mtlr 0
	addi 1,1,80
	blr
	.size	main,.-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 (Debian 3.4.6-9)"
