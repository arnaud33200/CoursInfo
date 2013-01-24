	.file	"main.c"
	.section	".text"
	.align 2
	.globl somme
	.type	somme, @function
somme:
	mr 11,3		// 
	li 0,0
	lwzx 0,11,0
	mr 3,0			// int s=0
	li 9,0			// int i=0
	cmpw 7,3,4		// est ce que le tableau contient des case	
	bgelr- 7
.L5:
	slwi 0,9,2
	lwzx 0,11,0		// adresse de base plus offset
	cmpw 7,3,0		// compare s avec t[i]
	bgt+ 7,.L6		// si s est plus grand que t[i]
	mr 3,0		// s += t[i]
.L6:
	addi 9,9,1		// i++
	cmpw 7,9,4		// compare i et l
	blt+ 7,.L5		// si i > l, allé à L5
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
