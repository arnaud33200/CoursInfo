#include <iostream>
#include <cstdlib>
#include <string>
#include<fstream>

#include "const.hh"

using namespace std;


/************************************************************
 * Nom fonction : Solution Colonne.
 * Nom / Date : YGORRA Virgile 1.0 	/ 23/11/2010
 * Description : La fonction vérifie si trois ou plus de trois diamants sont alignés verticalement et à la suite, si c'est le cas, cette fonction modifie les coordonnées du premier et du dernier diamant. Les coordonnées sont celles des diamants de la dernière solution. S'il n'y a pas de solutions, alors ces coordonnées seront de -1.
 * Entrées : Grille de jeu, Coordonnées du premier diamant et coordonnées du dernier diamant de la solution.
 * Sorties :Grille de jeu, Coordonnées du premier diamant et coordonnées du dernier diamant de la solution.
************************************************************/
void solutionligne(int tab[][G_SIZE], int & fc, int & fl, int & lc, int & ll)
{
	
	int i,c,l,cpt;

	
	c=0;
	cpt=1;
	
	while(l<8)
	{
		
		for(l=1;l<8;l++)
		{
			if(tab[l][c] == tab[l][c-1])
			{
				cpt++;
				if(cpt>=3){
				fl=l;
				fc=c-cpt+1;
				ll= l;
				lc= fc;
	
			
				}
			}
			else
			{
				cpt=1;
			}
		
		} // fin du for.
		c++;
		cpt =1;
	} // fin du tant que.
	
}


/************************************************************
 * Nom fonction : Solution Ligne
 * Nom / Date : YGORRA Virgile 1.0 	/ 23/11/2010
 * Description : La fonction vérifie si trois ou plus de trois diamants sont alignés verticalement et à la suite, si c'est le cas, cette fonction modifie les coordonnées du premier et du dernier diamant. Les coordonnées sont celles des diamants de la dernière solution. S'il n'y a pas de solutions, alors ces coordonnées seront de -1.
 * Entrées : Grille de jeu, Coordonnées du premier diamant et coordonnées du dernier diamant de la solution.
 * Sorties :Grille de jeu, Coordonnées du premier diamant et coordonnées du dernier diamant de la solution.
************************************************************/

void solutioncolone(int tab[][G_SIZE], int & fc, int & fl, int & lc, int & ll)
{
	
	int c,l,cpt;
	bool bon;
	
	l=0;
	
	while(l<G_SIZE-1 && !bon)
	{	
		c=0;	
		bon=0;
		cpt=0;
		while(c<G_SIZE)
		{
			if(tab[c][l] == tab[c+1][l])
			{
				cpt++;
				if(cpt>=3)
				{
					fc=c-cpt-1;
					fl=l;
					ll= l;
					lc= fc;
					bon=1;
				}
			}
			else
			{
				cpt=0;
			}
		c++;
		} // fin du for.
		l++;
	} // fin du tant que.
		
}
