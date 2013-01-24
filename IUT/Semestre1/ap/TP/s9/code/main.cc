#include<iostream>
#include<cstdlib>

#include "view.hh"
#include "saisir.hh"
#include "end.hh"
#include "const.hh"

using namespace std;



void 
changeplayer (int &joueur)
{
	if ( joueur == 1 )
		joueur=2;
	else
		joueur=1;
}

int main()
{
	int joueur=1;
	int tabM[nbcase][nbcase];
	int i;
	int j;
	
	bool end=0, win=0;
	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// * VIEW.CC
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	initgrille(tabM);
	affichergrille(tabM);
	
	cout << endl << "debut du jeu morpion : " 
	<< endl << endl;

	do
	{
		cout << "au joueur " << joueur << " de jouer" << endl;
		
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// * SAISIR.CC
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
		saisirpos(tabM, i, j);
		poserM(tabM, i, j, joueur);
		
		cout << endl << "#################################" << endl;
	
		affichergrille(tabM);
			
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		// * END.CC
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		
		end=fini(tabM);
		win=gagne(tabM, joueur);
				/****************************
				 * le texte du gagnant est dans VERIF.CC
				*****************************/
	
	changeplayer(joueur);	

		
	}
	while ( not win && not end );
	
	return 0;
}
 
