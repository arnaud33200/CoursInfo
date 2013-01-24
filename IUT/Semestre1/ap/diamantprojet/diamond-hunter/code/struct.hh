/*
########################################################################
#                                                                      #
#   Regroupe toutes les structures utilisées dans le jeu.              #
#                                                                      #
########################################################################
*/

#ifndef STRUCT_HH
#define STRUCT_HH

/**********************************************************
 * Structure diamant : donne differents etats d'un diamant

 Permet de faire la différence d'etat entre chaque diamant
	 de la grille : certain sont selectionnés
		et certain sont issus d'un echange impossible.
		 	  . . . etc
***********************************************************/
struct diamond
{	
	int color;
	SDL_Rect position;
	SDL_Rect lecture;
	bool cross;
	bool sele;
	bool blue;
} ;
	

/**********************************************************
 * Structure diamant : donne differents etats d'un diamant

	Cette structure permet de regrouper plusieurs déclarations
	et donc d'éviter de rentrer une multitude de paramètres dans
	chaque fonction du jeu 
***********************************************************/	
	
struct board
{

	diamond matrice[8][8];   // Matrice de diamant.
	 
	int score;	 // Score du joueur.
	int TIMEGAME; // temps dans le jeu
	int G_SIZE;  // taille de la grille
	int NB_SIZE;  // nombre de diamant
	int midleadd;  // ecart entre la grille et la bordure (en pixel)
	
	int combinaison;	// si il y a des combos ?
	
	 int fi;  		// First i.
	 int fj;		// First j.
	 int li;		// Last i.
	 int lj;		// Last j.
	
/// Images utilisées pour le jeux	
	SDL_Surface *wallpapergame;
	SDL_Surface *diamsprite;
	SDL_Surface *diamspritenocolor;
	SDL_Surface *explosion;
	SDL_Surface *bonus;
	SDL_Surface *bonustexte;
	SDL_Surface *stoppause;
	SDL_Surface *bonusinfo;
	
/// Textes utilisé pour le jeux
	SDL_Surface *scorus;
	SDL_Surface *time;
	SDL_Surface *temps; 
	SDL_Surface *point;
		
/// La lecture de sprite 
	SDL_Rect le; // explosion
	SDL_Rect lb; // bonus
 };
 
 /**********************************************************
 * Structure saveconfig : permet de paramétrer le jeu
***********************************************************/
	// Permet d'enregistrer les modifications apportées par le joueur.
 struct saveconfig
 {
	 int level;  // modification du jeu ?
	 //~ int temps;  // temps du jeu.
	 //~ int taillegrille;  // taille de la grille.
	 //~ int nbdiams; // nombre de diamants.
 };
 

#endif
