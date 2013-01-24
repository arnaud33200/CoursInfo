#ifndef PILE_H
#define PILE_H

#include<exception>

//===================================
// Classe Pile avec tableau de taille static
//===================================

template < class T >
class Pile {
	private:
		static const int TAILLE_PILE = 20; 
		T m_corps[TAILLE_PILE];
		int m_sommet;

	public:
// Constructeurs
		Pile();
		Pile(const Pile &p);

// Destructeur
		~Pile();

		void empiler(const T& elem);
		void depiler();
		
		T valeurSommet() const;
		bool pileVide() const;
		bool pilePleine() const;
};

class ExceptionPile : public exception
{
	public :
		ExceptionPile( const char * raison ) throw();
};

#include "Pile.cxx"
#endif
