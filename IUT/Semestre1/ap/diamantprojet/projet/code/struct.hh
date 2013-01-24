/*
##########################################################################
#                                                                        #
#   regroupe toutes les structures utilisées dans jeu                    #
#                                                                        #
##########################################################################
*/

#ifndef STRUCT_HH
#define STRUCT_HH

/**********************************************************
 * structure diamand : donne different etat d'un diamant
***********************************************************/
	// permet de faire la différence d'etat entre chaque diamant
	// de la grille : certain sont selectionné
	//				  certain sont issue d'un echange impossible
	// 			 	  . . . etc
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
 * structure diamand : donne different etat d'un diamant
***********************************************************/
	// cette structure permet de regroupé plusieur déclarion
	// et donc d'évite a rentré une multitude de parametre dans
	// chaque fonction du jeu
struct board
{

	diamond matrice[8][8];   // matrice de diamand
	 
	int score;	 // score du joueur
	int TIMEGAME;
	int G_SIZE;
	int NB_SIZE;
	int midleadd;
	
	//~ bool restsoluce;	// si plus aucune solution ?
	int combinaison;	// si il y a des combo ?
	
	 int fi;  		// first i
	 int fj;		// first j
	 int li;		// last i
	 int lj;		// last j
	
/// images utilisé pour le jeux	
	SDL_Surface *wallpapergame;
	SDL_Surface *diamsprite;
	SDL_Surface *diamspritenocolor;
	SDL_Surface *explosion;
	SDL_Surface *bonus;
	SDL_Surface *bonustexte;
	SDL_Surface *stoppause;
	SDL_Surface *bonusinfo;
	
/// textes utilisé pour le jeux
	SDL_Surface *scorus;
	SDL_Surface *time;
	SDL_Surface *temps; 
	SDL_Surface *point;
		
/// la lecture de sprite 
	SDL_Rect le; // explosion
	SDL_Rect lb; // bonus
 };
 
 /**********************************************************
 * structure saveconfig : permet de paramétré le jeu
***********************************************************/
	// permet d'enregistré les modifs apporté par le joueur
 struct saveconfig
 {
	 int level;  // modification du jeu ?
	 //~ int temps;  // temps du jeux
	 //~ int taillegrille;  // taille de la grille
	 //~ int nbdiams; // nombre de diamants
 };
 

#endif
