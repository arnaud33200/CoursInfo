#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;



void menu() {

  int choix;
  cout << "1. Exercice sur l'adition." << endl;
  cout << "2. Exercice sur la soustraction." << endl;
  cout << "3. Exercice sur la multiplication." << endl;
  cout << endl;
  cout << "            votre choix: "; 
}


// j'ai du deplacé le "sra

int genoperande() {
  int a;  
 a = (int) (10.0 * rand() / RAND_MAX);
   return a; 
}



int main() {

 string op;
 int choix, a, b, resultat;
 srand(time(NULL));
a=genoperande();
b=genoperande(); 

 cout << "a = " << a << endl;
 cout << "b = " << b << endl;
 cout << endl;
  menu();
 cin >> choix;
 cout << endl;
 switch (choix){
  case 1:
    cout << "excercice sur l'adition." << endl;
    resultat=a+b;
    op="+";
    break;
  case 2:
    cout << "excercice sur la soustraction." << endl;
    resultat=a-b;
    op="-";
    break;
  case 3:
   cout << "excercice sur la multiplication." << endl;
   resultat=a*b;
   op="*";
    break; 
 default:
   cout << "pas compris O_o ? " << endl;
   return 0; }

 cout << endl << endl << "==========================" << endl << endl;

 cout << "quel est le resultat de " << a << " " << op << " " <<  b << " ? : "; cin >> choix;
 if (choix==resultat)
   cout << "bravo ^^" << endl;
 else
   cout << "perdu ><" << endl;

  return 0; 
}
