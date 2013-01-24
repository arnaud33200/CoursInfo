#include<iostream>

#include "Pile.h"

template<class T>
Pile<T>::Pile()
: m_taille_pile(TAILLE_BLOC),
m_sommet(-1)
{
	m_corps = new T[TAILLE_BLOC];
}

template<class T>
Pile<T>::Pile(const Pile<T> & p)
: m_taille_pile(p.m_taille_pile),
m_sommet(p.m_sommet)
{
	m_corps = new T[m_taille_pile];
	for(int i=0; i<m_taille_pile; i++)
		m_corps[i] = p.m_corps[i];
}

template<class T>
Pile<T>::~Pile()
{
	delete[] m_corps;
}

template<class T>
T Pile<T>::valeurSommet() const
{
	return m_corps[m_sommet];
}

template<class T>
void Pile<T>::empiller( const T & element)
{
	if ( m_sommet >= m_taille_pile )
		agrandir();
	m_sommet++;
	m_corps[m_sommet]=element;
}

template<class T>
void Pile<T>::depiler()
{
	m_sommet--;
}

template<class T>		
bool Pile<T>::pileVide() const
{
	return ( m_sommet < 0 );
}

template<class T>
int Pile<T>::taillePile() const
{
	
	return m_sommet +1;
}	

template<class T>
void Pile<T>::agrandir()
{
	T* tmp = new T[m_taille_pile+TAILLE_BLOC];
	for ( int i=0; i<m_taille_pile; i++)
		tmp[i] = m_corps[i];
	delete[] m_corps;
	m_corps = tmp;
}
		

	
