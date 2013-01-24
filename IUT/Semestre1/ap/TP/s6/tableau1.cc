#include<iostream>
#include<cstdlib>
using namespace std;

const int T=100;

void saisirTableau(int tab[], int taille)
{
  int i;
  for( i = 0 ; i < taille ; i++ )        
    do 
      {
	cin >> tab[i];
	if (tab[i]<0 || tab[i]>20)
	  cout << "retapé votre notes" << endl;
	
      }
    while (tab[i]<0 || tab[i]>20);
}

void afficherTableau(int tab[], int taille)
{
  int i;
  for( i = 0 ; i < taille ; i++)
    cout << tab[i] << " ";
  cout << endl;
}

int indicemax(int tab[], int taille)
{
  int i;
  int indice;
  indice=0;
  for( i = 0; i<taille; i++)
    if (tab[indice]<tab[i])
      {
	indice = i;
      }
  return indice;
}

void indicemax2(int tab[], int taille, int &imax)
{
  int i;
  imax=0;
  for ( i= 1; i<taille; i++ )
    if ( tab[imax] < tab[i] )
      imax=i;
}

void inittabzero(int tab[], int taille)
{
  for (int i=0; i<taille; i++)
    tab[i]=0;
}

void compteoccurrences(int tab[], int taille, int compteur[], int taille_cpt)
{
  for ( int i=0; i<taille; i++)
    compteur[tab[i]]+=1;
  for ( int i=0; i<taille_cpt; i++)
    if ( compteur[i] != 0 )
      cout << i << " apparait " << compteur[i] << " fois" << endl;
}


int mediane(int taille, int compteur[], int taille_cpt)
{
  int effectif=0;
  for ( int i=0; i<taille_cpt; i++)
    if ( compteur[i]!=0 )
      effectif+=(i*compteur[i]);

  cout << endl << "mediane = ";
  cout << (effectif/taille)+1 << endl;
}

int main()
{
  const int TAILLE = 13;
  const int TAILLE_CPT = 21;
  
  int tabc[TAILLE_CPT];
  int tabl[TAILLE];
  int imax;
  
  inittabzero(tabc, TAILLE_CPT);
  
  saisirTableau(tabl, TAILLE);
  afficherTableau(tabl, TAILLE);
  indicemax2(tabl, TAILLE, imax);
 
  cout << "valeur max : tab[" << imax << "] = " << tabl[imax] << endl;
  // cout << "valeur max : tab[" << indicemax(tabl, TAILLE) << "] = " << tabl[indicemax(tabl, TAILLE)] << endl;

  cout << endl;
  compteoccurrences(tabl, TAILLE, tabc, TAILLE_CPT);
  mediane(TAILLE, tabc, TAILLE_CPT);

  return EXIT_SUCCESS;
}
