#include<iostream>
#include<cstdlib>
using namespace std;

const int taille =10;
void afficheNom(char tab[taille]){ }

bool estPresent(int val){ }

double racine(double valeur) { }

bool void afficheDate(bool val) { }

int main() {

  afficheNom("bonjour");
  char bonjour[taille]="bonjour";
  afficheNom(bonjour);
  bool res;
  estPresent(4);
  estPresent('4');
  res=estPresent(4.0);
  double val=racine(4.0);
  double valRac=5.4;
  afficheDate(res);
  afficheDate(true);
  afficheDate(false);
  int a=afficheDate(false);
  afficheDate(false);
  

    return 0;
}

