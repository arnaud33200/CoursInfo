#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
   int a;
   int i;

   // fonction permettant d'initialiser le germe 
   // de la série aléatoire en fonction de l'heure courante ; 
   // la série varie donc d'une exécution à l'autre.
   
   srand(time(NULL));

   for (i = 0; i< 10; i++)
     {
       a = (int) (10.0 * rand() / RAND_MAX);
       cout << a << endl;
     }
 
}
