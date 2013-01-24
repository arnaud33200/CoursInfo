// Liste.cxx

#include <iostream>
#include <cassert>
#include "Liste.h"

using namespace std;

template <class T>
const int Liste<T>::TAILLE_BLOC_BASE = 5;

template <class T>
Liste<T>::Liste()
{
  //constructeur
  m_tailleBloc = TAILLE_BLOC_BASE;
  m_bloc = new Cellule<T>[m_tailleBloc];
  m_premier = NUL;
  m_premierLibre = 0;
  //chaînage cellules libres
  for(int i=0;i< m_tailleBloc-1;i++)
    m_bloc[i].suivant = i+1;
  m_bloc[m_tailleBloc-1].suivant = NUL;
}

template <class T>
Liste<T>::~Liste()
{
  delete[] m_bloc;
}

template <class T>
typename Liste<T>::TAdresse
Liste<T>::adressePremier() const
{
	return m_premier;
}

template <class T>
typename Liste<T>::TAdresse
Liste<T>::adresseSuivant( TAdresse adr ) const
{
	return m_bloc[adr]->suivant;
}

template <class T>
T Liste<T>::valeurElement( TAdresse adr ) const
{
	return m_bloc[adr]->info;
}

template <class T>
void Liste<T>::modifierValeur( const T& elem, TAdresse adr )
{
	m_bloc[adr]->info = elem;
}

template <class T>
void Liste<T>::afficher() const
{
	TAdresse adr = m_premier;
	while ( adr != NUL )
	{
		cout << m_bloc[adr]->info;
		adr = adresseSuivant(adr);
		if ( adr != NUL )
			cout << " - ";
	}
	cout << endl;
}

template <class T>
Liste<T>::Liste( const Liste<T> & liste )
{
  //constructeur de copie
  dupliquer( liste );
}

template <class T> 	
Liste<T> & 
Liste<T>::operator=( const Liste<T> & liste )
{
  //opérateur d'affectation
  if ( this != &liste ) {
    delete [] m_bloc;
    dupliquer( liste );
  }
  return *this;
}

template <class T>
void 
Liste<T>::dupliquer( const Liste<T> & liste )
{
  // copie liste dans la liste courante qui doit être "vide" à l'appel
  // en particulier, m_bloc ne doit pas etre alloue
  m_tailleBloc = liste.m_tailleBloc ;
  m_premier = liste.m_premier;
  m_premierLibre = liste.m_premierLibre;
  m_bloc = new Cellule<T>[m_tailleBloc];
  for(int i=0; i<m_tailleBloc; i++)
    m_bloc[i] = liste.m_bloc[i] ;
}
 	
template <class T>
void 
Liste<T>::agrandir() 
{
  // lorsqu'une insertion est demandée alors que le bloc
  // est plein
  Cellule<T> * tmp;
  tmp= new Cellule<T>[m_tailleBloc+TAILLE_BLOC_BASE];
  int i;
  // recopie bloc
  for (i=0; i<m_tailleBloc; i++)
    tmp[i] = m_bloc[i];
  //chaînage nouveaux blocs libres
  for(i=0; i < TAILLE_BLOC_BASE-1; i++)
    tmp[m_tailleBloc+i].suivant = m_tailleBloc+i+1;
  //libération ancienne zone
  delete[] m_bloc;
  //mises à jour
  m_premierLibre = m_tailleBloc;
  m_tailleBloc += TAILLE_BLOC_BASE;
  m_bloc = tmp;
  m_bloc[m_tailleBloc-1].suivant = NUL;
}

//les primitives classiques d'insertion / suppression
template <class T>
void 
Liste<T>::insererEnTete( const T&  element )
{
  if ( m_premierLibre == NUL )
    agrandir();
  TAdresse premLib = m_bloc[m_premierLibre].suivant;
  m_bloc[m_premierLibre].info = element;
  m_bloc[m_premierLibre].suivant = m_premier;
  m_premier = m_premierLibre;
  m_premierLibre = premLib;
}

template <class T>
void 
Liste<T>::insererApres(const T& element, TAdresse adr )
{
  assert ( adr>=0 && adr<m_tailleBloc);

  if ( m_premierLibre == NUL )
    agrandir();
  TAdresse premLib = m_bloc[m_premierLibre].suivant;
  m_bloc[m_premierLibre].info=element;
  m_bloc[m_premierLibre].suivant = m_bloc[adr].suivant;
  m_bloc[adr].suivant = m_premierLibre;
  m_premierLibre = premLib;
}

template <class T>
void
Liste<T>::supprimerEnTete() 
{
  assert ( m_premier != NUL );

  TAdresse prem = m_premier;
  m_premier = m_bloc[m_premier].suivant;
  m_bloc[prem].suivant = m_premierLibre;
  m_premierLibre = prem;
}

template <class T>
void 
Liste<T>::supprimerApres( TAdresse adr )
{
  assert ( adr>=0 && adr<m_tailleBloc);

  TAdresse suppression = m_bloc[adr].suivant;
  m_bloc[adr].suivant = m_bloc[suppression].suivant;
  m_bloc[suppression].suivant = m_premierLibre;
  m_premierLibre = suppression;
}


// A compléter
