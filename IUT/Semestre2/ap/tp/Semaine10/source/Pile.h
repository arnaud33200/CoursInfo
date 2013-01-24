///////////////////////////////////////////////////////////////////////////////
// Pile.h
// Version : ID 2008/03/28 modification class<==> typename + include .cxx dans .h
///////////////////////////////////////////////////////////////////////////////

#ifndef _PILE_H_
#define _PILE_H_

//- Definit un modele pour manipuler une pile de taille maximale donnee.
template<typename TInfo>
class Pile
{

private:
  //- Tableau alloue dynamiquement de 'TInfo'.
  TInfo* m_sp;
  //- Position du sommet de la pile dans le tableau 'm_sp'.
  int m_sommet;
  //- Constante de classe donnant la taille maximale possible pour la pile.
  static const int TAILLE_PILE;
  
public:
  //- Constructeur par defaut.
  Pile();
  //- Destructeur.
  ~Pile();
  //- Constructeur de copie.
  //- @param other la pile a recopier.
  Pile( const Pile<TInfo> & other );
  // @return la valeur situee sur le sommet de la pile.
  TInfo valeurSommet() const;
  //- Empile la valeur [val] donnee en parametre.
  //- @param val une valeur.
  void empiler( const TInfo & val );
  //- Depile.
  void depiler();
  //- @return 'true' si la pile etait vide, 'false' sinon.
  bool pileVide() const;

}; // template<class TInfo> class Pile

// JOL : 2000/10/11
// Force l'instanciation de ce model pour les deux types char et float.
// => Cela evite de mettre toute la definition de la classe Pile dans l'en-tete.
// => en revanche, il faut penser a rajouter des lignes similaires lorsque l'on
//    instancie ce modele pour une nouvelle classe.
//template class Pile<char>;
//template class Pile<float>;

// ID : 2008/03/25
// Cette solution ci-dessus ne fonctionne plus avec les nouveaux compilateurs
// Donc :
// 
// CL : 2008/03/25
// il faut proceder autrement en incluant les definitions directement
// par contre, il faut veiller a ne pas laisser
// #include "Pile.h" dans Pile.cxx puisque dans ce cas,
// il n'y a rien pour resoudre l'inclusion croisee..
// NB: l'extension ".cxx" aide à distinguer un template d'un ".cc"
// NB2: le make ne produit plus de Pile.o mais c'est lors de la creation
// des autres fichiers objet que les ~Pile<XXX>.o sont crees..
#include "Pile.cxx"

#endif // #ifndef _PILE_H_

