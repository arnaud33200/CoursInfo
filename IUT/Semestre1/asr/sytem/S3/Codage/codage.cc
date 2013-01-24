/*
Programme obscur
   Lire Documentation.txt
   auteur: aladouce
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;



void usage() {
    cerr<<"Usage : parite\n";
    exit(EXIT_FAILURE) ; }


void proc (string ligne) {
    int d=0;
    int coefficients[100];         

 /* traduction de la ligne en tableau de coefficients */

    for (int position=ligne.length () ; position>=0;
            position--) {
        switch (ligne[position]) {
        case '0':
            coefficients[d++]=0;
            break;
        case '1':
            coefficients[d++]=1;
            break;
        default:
            break; 		// les autres caractères sont ignorés
        }
    };
    if (d==0) return;

    /* calcul de la parité */

    int parite=0;
    for (int k=0; k<d; k++)  if (coefficients[k]==1)  parite= (1-parite) ;

    /* affichage */

    for (int k=d-1; k>=0; k--) cout<<coefficients[k];
    cout << " "<<parite<<"\n";
}



int main  (int argc, char *argv[])  {
    char ligne[100];
    if  (argc!=1) usage () ;
    while (1) {
        cin.getline (ligne,100) ;
        if (cin.eof () )
            break;
        proc (ligne) ;
    };
}
