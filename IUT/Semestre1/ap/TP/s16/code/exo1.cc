#include<iostream>
#include<cstdlib>
using namespace std;
const int taille=5;
void TinkyWinky(int *n, int * &ptr)
{
ptr=new int[taille];
int cpt=0;
  do
  {
    *(ptr+cpt)=n[cpt];	
    cpt++;
  }
  while (cpt < taille);
}
void Dipsy(int *n)
{
for (int i=0; i< taille;i++){
	n[i]=i;
	}
cout << endl;
}
void LaaLaa(int *n)
{
for (int i=0; i< taille;i++)
	cout << *(n+i);
cout << endl;
}
void Po(int *n, int*b)
{
int *c=n;
for (int i=0; i< taille-1;i++)
	n++;
int i=0;
while (c!=n){
	b[i]=*n;
	n--;
	i++;
}
}
int main()
{  
int *p;
int *tabA=new int[taille];
int *tabB;
Dipsy(tabA);
LaaLaa(tabA);
TinkyWinky(tabA,tabB);
LaaLaa(tabB);
Po(tabA,tabB);
LaaLaa(tabB);
return EXIT_SUCCESS;
}
