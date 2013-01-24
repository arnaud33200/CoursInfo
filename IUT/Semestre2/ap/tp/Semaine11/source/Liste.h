///////////////////////////////////////////////////////////////////////////////
// Liste.h
//
// Author: JOL 2000/10/20
// Version : MM 2002/02/20 quelques détails de présentation 
// Version : ID 2002/03/19 prototype insererApres comme en ASD
// Version : MM 2004/03/05 Liste<Etudiant>,
//                         suppression de afficher()
// Version : ID 2008/03/28 modification class<==> typename + include .cxx dans .h
///////////////////////////////////////////////////////////////////////////////

#ifndef _LISTE_H_
#define _LISTE_H_

// Utilise la STL.
#include <list>
#include <string>

using namespace std;

//- Definit un modele pour manipuler une liste de taille quelconque.
template<typename TInfo>
class Liste {
public :
  // Alias pour 'TIterator'.
  typedef typename list<TInfo>::iterator TIterator;
  // ------------------------- services standards -----------------------------
  Liste();
  ~Liste();
  Liste( const Liste & other );
  Liste & operator=(const Liste & other);
   
  // ------------------------- services usuels de listes ----------------------
 
  TIterator adressePremier() const;
  TIterator adresseSuivant( TIterator adr ) const;
  TInfo valeurElement( TIterator adr ) const;
  void modifieValeur( TIterator adr, const TInfo & valeur );
  void insererEnTete( const TInfo & valeur );
  void insererApres( const TInfo & valeur, TIterator adr );
  void supprimerEnTete();
  void supprimerApres( TIterator adr );
  
  TIterator null() const;

  // ------------------------- services pour debuguer ----------------------

  void erreur( const string & msg ) const;

 private:
  mutable list<TInfo> m_list;

};

// idem que pour les fichiers Pile
#include "Liste.cxx"

// TOUT CA NE FONCTIONNE PLUS
// JOL : 2000/10/20
// Force l'instanciation de ce modele pour les types char, int et float.
// => Cela evite de mettre toute la definition de la classe Liste dans l'en-tete.
// => en revanche, il faut penser a rajouter des lignes similaires lorsque l'on
//    instancie ce modele pour une nouvelle classe.
//template class Liste<char>;
//template class Liste<int>;
//template class Liste<float>;
// MM : 2004/05/04
//template class Liste<Etudiant>;
//typedef Liste<Etudiant>::TIterator TAdresse;

#endif
