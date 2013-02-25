#include "colors.inc"
#include "textures.inc"


// Definition de la camera
camera
{
  // Type de camera
  perspective  

  // Emplacement de la camera
  location <0, 5, 10>
  // Direction vers ou regarde la camera
  look_at <0, 0, 0>

  // Parametre de la camera, dans le cas de l'utilisation de perspective  
  angle 45
}



// Declaration d'un objet de type "box"
#declare boite = box
{
  // Position des 2 coins de la boite
  <-1, -1, -1>, <1, 1, 1>
  // Couleur de cet objet
  pigment {color rgb <1.0, 0.5, 0.0>}
}


// Declaration d'un objet de type "sphere"
#declare boule = sphere 
{	
  // Position et rayon de la sphere
  <0,0,0>, 1.3
  texture { Sapphire_Agate }
}


// Declaration d'une composition entre les deux objets precedents
// meme chose avec union, intersection, merge, 
#declare diff = difference
{
  object {boite}
  object {boule}
}


// Autre possibilite de declaration
#declare diff2 = difference
{
  box
  {
    <-1, -1, -1>, <1, 1, 1>
    pigment {color rgb 1}
  }

  cylinder
  {	 
    // Centres des 2 extrémités
    <0, -2, 0>, <0, 2, 0>      
    // Rayon
    1       
    pigment {color rgb 1}
  }
}


// Definition d'une source lumineuse
light_source
{
  // Position de la lumiere
  <3, 5, 0>
  // Couleur de la source lumineuse
  color White
}
 

// Exemple de source lumineuse de type spotlight 
light_source
{
  <0, 2.5, 5>
  color White
  spotlight  
  point_at <1, 0, 0>
  radius 7
  falloff 10 
  tightness 1
}



// Affichage ou non des objets

// Les objets prédéclarés: 
// qu'on appelle de cette manière
//object {boite}
// ou eventuellement par ce raccourci
//boite
//boule
//diff
//diff2
      
      
// auxquels on peut appliquer des transformations:
// translation d'un vecteur 3d
//object {diff2 translate <-1, -1, 0>}

// ou rotation d'un angle en degres suivant chacun des 3 vecteur unitaires
//object {diff rotate <45, 45/2, 45/4>}

// ou mise a l'echelle, et eventuellement combinaison de transformations
object {difference {object {boule} object {boite}} scale <2.0, 0.25, 5.0> translate <0, 0, -3>}