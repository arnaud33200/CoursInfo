#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "outil.h"

class Rationnel
{
	private:
/// ########### les atributs ################### ///
		int my_num;
		int my_deno;
		
	public:
/// ########### les methodes ################### ///
		void affiche() const;
		void transforme();
		bool egalite( Rationnel p);
	// les opérations		
		void addition(Rationnel p, Rationnel & resultat);
		void soustraction(Rationnel p, Rationnel & resultat);
		void multiplication(Rationnel p, Rationnel & resultat);
		void division(Rationnel p, Rationnel & resultat);
	// les outils
		void reducteur();
		
/// ########### les constructeurs ############# ///
		Rationnel();
		Rationnel(int n, int d);
		
/// ########### les accesseurs ############### ///
		void setNum( int n );
		void setDeno( int d );
		int getNum() ; 
		int getDeno() ;
				
};

#endif
