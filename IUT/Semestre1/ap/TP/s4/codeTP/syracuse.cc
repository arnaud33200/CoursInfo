#include <iostream>
using namespace std;

int main()
{
  int u_n, u_n_1;
  bool vol_atteint = false;

  cout << "Entrez le premier terme de la suite (valeur entière positive)" 
       << endl;
  cin >> u_n_1;

  if (u_n_1 <= 0)
    {
      cout << "erreur de saisie !!!";
      return 0;
    }
  else
    {
      vol_atteint = (u_n_1 == 1);
      while (!vol_atteint)
        {
          if (u_n_1 % 2 == 1)
            {
              u_n = 3*u_n_1 + 1;
            }
          else
            {
              u_n = u_n_1 / 2;
            }
          cout << u_n << endl;
         
          u_n_1=u_n;       
        }
    }

  return 0;
}
