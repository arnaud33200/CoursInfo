// Liste.cxx

#include <iostream>
#include <cassert>
#include "Liste.h"

using namespace std;

template <class T>
Liste<T>::Liste() 
{
  m_premier = NULL;
}

template <class T>
Liste<T>::~Liste()
{
   while ( m_premier != NULL )
     supprimerEnTete();
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
	return adr->suivant;
}

template <class T>
T
Liste<T>::valeurElement( TAdresse adr ) const
{
	return adr->info;
}

template <class T>
void
Liste<T>::modifierValeur( const T& elem, TAdresse adr )
{
	adr->info = elem;
}

template <class T>
void
Liste<T>::insererEnTete( const T& elem )
{
  TAdresse aux = new Cellule<T>;
  aux->info = elem;
  aux->suivant = m_premier;
  m_premier = aux;
}

template <class T>
void
Liste<T>::supprimerEnTete()
{
  assert ( m_premier != NULL );
  TAdresse aux = m_premier;
  m_premier = m_premier->suivant;
  delete aux;
}

template <class T>
void Liste<T>::insererApres( const T& elem, TAdresse adr )
{ 
	TAdresse aux = new Cellule<T>;
	TAdresse next = adresseSuivant(adr);
	aux->info = elem;
	aux->suivant = next;
	adr->suivant = aux;
	
}

template <class T>
void Liste<T>::supprimerApres( TAdresse adr )
{
  // à faire
}


template <class T>
void Liste<T>::afficher() const
{
	TAdresse adr = m_premier;
	if ( m_premier == NULL ) 
		cout << "(La liste est vide)";
	while ( adr != NULL )
	{
		cout << valeurElement(adr);
		adr = adresseSuivant(adr);
		if ( adr != NULL )
			cout << " - ";
	}
	cout << endl;
}

template <class T>
void Liste<T>::placer(const T& elem)
{
	bool bon = false;
	TAdresse adr = m_premier;
	TAdresse next;
	
	if ( valeurElement(adr) >= elem )
		insererEnTete(elem);
	else
	{
		if ( adr != NULL )
		{
			adr = adresseSuivant(adr);
			next = adresseSuivant(adr);
		}
		while ( next != NULL && not bon )
		{
			if ( valeurElement(next) >= elem )
			{
				insererApres(elem, adr);
				bon = true;
			}
			adr = next;
			next = adresseSuivant(adr);
		}
		if ( not bon ) // si on a trouvé aucun elément
		{
			insererApres(elem,adr);
		}
	}
}

template <class T>
bool Liste<T>::estTrie() const
{
	bool bon = true;
	TAdresse adr = m_premier;
	TAdresse next;
	if ( adr != NULL )
		next = adresseSuivant(adr);
	while ( next != NULL && bon == true )
	{
		if ( valeurElement(adr) > valeurElement(next) )
			bon = false;
		adr = next;
		next = adresseSuivant(adr);
	}
	return bon;
}
