#ifndef PILE_H
#define PILE_H

template<class T>
class Pile
{
	private :
		static const int TAILLE_BLOC = 10;
		int m_taille_pile;
		T* m_corps;
		int m_sommet;
		
		void agrandir();
		
	public :
		Pile();
		Pile(const Pile<T> & p);
		~Pile();
		T valeurSommet() const;
		void empiller( const T & element);
		void depiler();
		
		bool pileVide() const;
		int taillePile() const;			
};

#include "Pile.cxx"
#endif 
