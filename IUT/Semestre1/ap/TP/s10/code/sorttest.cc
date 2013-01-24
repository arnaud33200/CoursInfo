#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{

  int n;
  cin >> n;
  srand(time(NULL));
  for (int i=0; i<n; i++)
    {
      cout << rand()%(n-0)+0 << " ";
    }

  return 0;
}
