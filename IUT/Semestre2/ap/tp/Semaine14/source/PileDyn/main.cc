#include "Pile.h"
#include <iostream>
#include <stack>

using namespace std;

template<class T>
void clonerPile( const Pile<T> & p, Pile<T> & p_clone)
{
	Pile<T> tmp;
	T element;
// on vide la pile clone au cas ou elle ne l'est pas
	while ( !p_clone.pileVide() )
		p_clone.depiler();
		
	while ( !p.pileVide() )
	{
		element = p.valeurSommet();
		p.depiler();
		tmp.empiller( element );
	}
	
	while ( !tmp.pileVide() )
	{
		element = tmp.valeurSommet();
		tmp.depiler();
		p_clone.empiller( element );
	}

}

template <class T>
void inverserPile( Pile<T> & p )
{
	int taille = p.taillePile();
	T tmp[taille];
	T element;
	
	for ( int i=0; i<taille; i++)
	{
		element = p.valeurSommet();
		p.depiler();
		tmp[i] = element;
	}
	for ( int i=0; i<taille; i++)
		p.empiller(tmp[taille-i-1]);
}

void supprimerNegatif(Pile<int> &p)
{
	Pile<int> tmp;
	int element;
		
	while ( !p.pileVide() )
	{
		element = p.valeurSommet();
		p.depiler();
		if ( element >= 0 )
			tmp.empiller( element );
	}
	
	while ( !tmp.pileVide() )
	{
		element = tmp.valeurSommet();
		tmp.depiler();
		p.empiller( element );
	}
}

void testPerformancePile(Pile<int> &p)
{
	for(int i=0; i<1000; i++)
		p.empiller(i+1);
	while( !p.pileVide() )
		p.depiler();
}

void tesPerformanceStack(stack<int> &p)
{
	for(int i=0; i<1000; i++)
		p.push(i+1);
	while( !p.empty() )
		p.pop();
}

int main()
{
  	return 0;
}

