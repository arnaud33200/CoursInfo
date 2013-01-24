README

Projet de Dames
de Xavier JOUVENOT & Arnaud LADOUCETTE

/////////////////////////////////////////////////////////////////////
Fonctionnalité réalisé :
/////////////////////////////////////////////////////////////////////

	- Initialisation des cases du damier
	- Créer une nouvelle partie
	- Déplacer un pion en diaguonal
	- Manger un pion adverse
	- Changer de tour aprés l'action d'un joueur
	- possibilité q'un pion devienne une dame
	- Déplacer une dame
	- Manger un pion adverse avec une dame
	


/////////////////////////////////////////////////////////////////////
Fonctionnalité non réalisé :
/////////////////////////////////////////////////////////////////////

	- Sauvegarde partie ( probléme de sérialisation avec panel )
	- Charger partie ( probléme de sérialisation avec panel )
	- obligé a mangé lorsqu'un pion a l'occasion
	- faire des combinaisons en mangeant un pion adverse



/////////////////////////////////////////////////////////////////////
Architecture du programme :
/////////////////////////////////////////////////////////////////////

	-une classe Piece : représente les pions ou les dames grâce à l'utilisation d'un booléen
	-une classe CaseDamier : représente les case avec et sans piece
	-une classe Form : qui gére les evenements et la partie graphique

	Piece est intégrés dans dans CaseDamier
	CaseDamier hérite de la classe system Panel
	Form est composé de 100 caseDamier



/////////////////////////////////////////////////////////////////////
Choix de réalisation :
/////////////////////////////////////////////////////////////////////

	Nous avons décider de gérer les déplacements des pions à l'aide des fonctions MouseMove et MouseUp.
	Nous avons eu du mal à implémenté le drag and drop surtout dans le fait que les caseDamiers
	se créer aprés l'exécution du programme et qu'on ne savait pas récupérer tout les évenement relatif
	aux caseDamiers comme le mouse_down, le drag_over ... enfin du moins on a trouvé la solution bien
	trop tard pour pouvoir la mettre en place, et on était bien lancé avec notre méthode.



/////////////////////////////////////////////////////////////////////
Mode d'emploi :
/////////////////////////////////////////////////////////////////////

	La partie commence avec un damier vide. Pour lancer une partie, il faut clicker sur l'icone nouveau.
	Aisin le damier va s'initialiser avec tous les pions neccessaire pour commencer une partie.
	Ce sont les blancs qui commenceront. pour déplacer une pièce, il suffit juste de presser sur la pièce
	qu'on veut déplacer, et relacher le click de la sourie sur la case de déplacement voulu.
	Si un joueur sur le mauvais pions ( en fonction du tour ) une boite message apparaitra pour préciser
	à qui c'est le tour.
