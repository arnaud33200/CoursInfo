// Tableau.h
// Contient les entêtes des fonctions sur les tableaux
// dont les définitions se trouvent dans Tableau.cc


/**********************************************
 FONCTIONS DE SAISIES ET AFFICHAGES
 **********************************************/

void saisirTableau(int tab[], int & taille, int max);
void saisirTableauTrie(int tab[], int & taille, int max);
void afficherTableau(int tab[], int taille);


/**********************************************
 FONCTIONS DE RECHERCHE (POSITION ELEM)
 **********************************************/

int cherchePosSeq(int tab[], int taille, int elem);
int cherchePosDicho(int tab[], int taille, int elem);
int cherchePosSeqTrie (int tab[], int taille, int a);


/**********************************************
 FONCTIONS DE SUPPRESSION
 **********************************************/

void supprnontrie(int tab[], int &taille);


/**********************************************
 FONCTIONS D'AJOUT
 **********************************************/

void ajouterNonTrie(int tab[], int & taille, int elem);
void ajouterTrie(int tab[], int & taille, int elem);
