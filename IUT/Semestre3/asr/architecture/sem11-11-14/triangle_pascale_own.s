	.file	"triangle_pascale.c"
	.section	".text"
	.align 2
	.globl triangle
	.type	triangle, @function

triangle:
	li 8,0	
	li 9,0		
	cmpw 7,9,5
	bge 7,suiteOperation
	
boucleInit:
	slwi 10,9,2		
	stwx 8,3,10
	addi 9,9,1
	cmpw 7,9,5
	blt 7,boucleInit

suiteOperation:
	
	li 8,1
	stw 8,0(3)
	stw 8,4(3)
	li 10,1

trouverLigne:		
	li 9,1
	
boucleLigne:
	li 13,1				
	subf 12,13,9		
	slwi 0,12,2			
	lwzx 13,3,0		
	addi 0,0,4			
	lwzx 14,3,0
	add 14,14,13		
	stwx 14,4,0
	addi 9,9,1
	cmpw 7,9,5		
	blt 7,boucleLigne
	
    bl recopieTableau
    addi 10,10,1
    cmpw 7,10,6
	bge 7, recupColonne		
	b trouverLigne
	
recupColonne:
	slwi 5,5,2
	lwzx 3,3,5		
	blr

recopieTableau:
	mr 20,3
	mr 3,4
	mr 4,20
	blr
		
