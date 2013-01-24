	.file	"triangle_pascale.c"
	.section	".text"
	.align 2
	.globl triangle
	.type	triangle, @function
triangle:
//~~~~~~~~~~~~~	on travail sur une copie du talbeau	
	
	mr 23,3	
	mr 24,4
	
// ~~~~~~~~~~~~~~ initialiser les deux tableau ~~~~~~~~~~~~~~~~~
	
	li 8,0		// valeur a rentrer dans le tableau
	li 9,0		// incdice parcours colonne
	cmpw 7,9,5
	bge 7,suiteOperation
	
boucleInit:
	slwi 0,9,2		// cacule de l'offset	
	stwx 8,23,0
	addi 9,9,1
	cmpw 7,9,5
	blt 7,boucleInit

suiteOperation:
	li 8,1
	stw 8,23,0
	stw 8,23,4
	li 10,0

// ~~~~~~~~~~~~~~ cacule des lignes suivantes ~~~~~~~~~~~~~~~~~
trouverLigne:
	addi 10,10,1
	cmpw 7,10,6
	bge 7, recupColonne			// on verifi si on est a la bonne ligne
	li 9,1
	
boucleLigne:
	
	li 13,1				// valeur 1 pour faire - 1
	subf 12,13,9		// indice sur le tableau a copier
	slwi 0,12,2			// adresse valeur du tableau a copier
	lwzx 13,23,0		// enregistre la premier valeur
	addi 0,0,4			// adresse de la case suivante
	lwzx 14,23,0
	add 14,14,13		// somme a mettre dans le nouveau tableau
	stwx 14,24,0
	addi 9,9,1
	cmpw 7,9,5		// fin de remplir le tableau ?
	blt 7,boucleLigne
    bl recopieTableau	// on recopie le tableau 2 dans le 1
	b trouverLigne

//~~~~~~~~~~~ Fin de la fonction, aprés avoir trouvé la ligne, on retourne la colonne
	
recupColonne:
	stwx 3,23,5		// l'offset est dans le registre 6
	blr

//~~~~~~~~~~~~ Fonction pour recopier le tableau ~~~~~~~~~~~~
	
recopiTableau:
	mr 25,23
	mr 23,24
	mr 24,25
	blr
	
/*
	li 9,0
	cmpw 7,9,5
	bltlr 7
	
boucleCopie:
	slwi 0,9,2
	lwzx 11,24,0
	stwx 11,23,0
	addi 9,9,1
	cmpw 7,9,5
	bge 7, boucleCopie
	blr */
	
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
