#include <iostream>
#include "Liste.h"

using namespace std;

int main()
{
  // exemples de déclaration de listes
  Liste<int> li;
  li.afficher();
  li.insererEnTete(1);
  li.insererEnTete(3);
  li.insererEnTete(5);
  li.insererEnTete(6);
  li.insererEnTete(9);
  li.insererEnTete(6);
  li.insererEnTete(5);
  li.insererEnTete(6);
  li.afficher();
  li.placer(8);
  li.afficher();
  li.placer(15);
  li.afficher();

}
