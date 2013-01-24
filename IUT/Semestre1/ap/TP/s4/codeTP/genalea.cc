#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
   int a;
   int i;

   // fonction permettant d'initialiser le germe 
   // de la s�rie al�atoire en fonction de l'heure courante ; 
   // la s�rie varie donc d'une ex�cution � l'autre.
   
   srand(time(NULL));

   for (i = 0; i< 10; i++)
     {
       a = (int) (10.0 * rand() / RAND_MAX);
       cout << a << endl;
     }
 
}
