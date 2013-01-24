Version-03

Il faut maintenant gérér des salles verrouillées et des salles
contenant des clefs. Étant donné que nous ne pouvons pas modifier
l'implémentation du labyrinthe, nous n'avons pas beaucoup de choix.
(Un labyrinthe est une matrice de Salle.)

Mon choix : 
- SalleVerrouillee étend Salle (et non SallePiegee : je ne veux pas
trimballer une donnée que ne me sert à rien)
- SalleAvecClef étend Salle

Ici on voit bien que l'implémentation donnée pour un labyrinthe est un
frein : comment faire une salle verrouillée contenant un piège ? ou
bine une salle verrouillée contenant un piège et une clef ?

- HerosAvecVieEtObjet étend HerosAvecVie. On aurait pu faire ici une délégation.

Autre problème (plus difficile) : bob peut aller dans une salle verrouillée même si
celle-ci est verrouillée (les primitives de Bob le permettent).

Version-02

Ajout des points de vie du héros et des salles piégées :
utilisation de l'héritage avec la création des classes 
- HerosAvecVie qui étend Heros
- SallePiegee qui étend Salle


