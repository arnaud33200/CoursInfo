// Fichier main.cc

#include<iostream>
#include<cstdlib>
#include<sstream>
#include<string>
#include<cmath>

#include "Point.h"
#include "Boite.h"

using namespace std;

int main()
{
	Point p(2,4);
	Point a(3,5);
	Point c(2,6);
	Point d(7,6);
	Point e(4,3);
	cout << endl;
	Boite b(p);
	b.affiche();
	b.ajouterPoint(a);
	b.affiche();
	b.ajouterPoint(c);
	b.affiche();
	b.ajouterPoint(d);
	b.ajouterPoint(e);
	b.affiche();
	
	return 0;
}
