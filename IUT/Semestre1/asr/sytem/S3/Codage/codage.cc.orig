/* 
Programme obscur
   Lire Documentation.txt
   auteur: inconnu
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void u() { cerr<<"Usage : parite\n";  exit(EXIT_FAILURE) ;  }

void proc (string l) { int d=0; int t[100]; 
 /* traduction de la ligne en tableau de coefficients */
for (int p=l.length () ; p>=0; 
p--) { switch (l[p]) { case '0':t[d++]=0; break;  case '1':t[d++]=1; break; 
default:	 break; 		// les autres caractères sont ignorés
}}; 
if (d==0) return; 
/* calcul de la parité */ 
int b=0; for (int k=0; k<d; k++)  if (t[k]==1)  b= (1-b) ; 
/* affichage */ 
for (int k=d-1; k>=0; k--) cout<<t[k]; cout << " "<<b<<"\n"; 
}

int main  (int argc, char *argv[])  { char l[100]; 
if  (argc!=1) u () ;  while (1) { cin.getline (l,100) ; if (cin.eof () ) 
break; proc (l) ; }; 
}
