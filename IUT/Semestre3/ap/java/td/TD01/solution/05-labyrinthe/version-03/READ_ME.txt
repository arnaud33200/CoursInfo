Version-03

Il faut maintenant g�r�r des salles verrouill�es et des salles
contenant des clefs. �tant donn� que nous ne pouvons pas modifier
l'impl�mentation du labyrinthe, nous n'avons pas beaucoup de choix.
(Un labyrinthe est une matrice de Salle.)

Mon choix : 
- SalleVerrouillee �tend Salle (et non SallePiegee : je ne veux pas
trimballer une donn�e que ne me sert � rien)
- SalleAvecClef �tend Salle

Ici on voit bien que l'impl�mentation donn�e pour un labyrinthe est un
frein : comment faire une salle verrouill�e contenant un pi�ge ? ou
bine une salle verrouill�e contenant un pi�ge et une clef ?

- HerosAvecVieEtObjet �tend HerosAvecVie. On aurait pu faire ici une d�l�gation.

Autre probl�me (plus difficile) : bob peut aller dans une salle verrouill�e m�me si
celle-ci est verrouill�e (les primitives de Bob le permettent).

Version-02

Ajout des points de vie du h�ros et des salles pi�g�es :
utilisation de l'h�ritage avec la cr�ation des classes 
- HerosAvecVie qui �tend Heros
- SallePiegee qui �tend Salle


