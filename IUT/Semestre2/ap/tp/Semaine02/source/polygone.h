#ifndef POLYGONE_H
#define POLYGONE_H

#include <sstream>
#include <string>

#include "point.h"

using namespace std;

const int MAX = 10;

class Polygone
{

	private:
	
// ATTRIBUTS	
		Point my_tab[MAX];
		int my_taille;
		
	public:
	
// METHODES
		void saisie();
		string toString();
		void deplace(const float &dx, const float &dy);
		void ajoutSommet(const Point &p);
		float perimetre() const;

// ACCESSEUR
		int getT() const;
		void setT(const int &t);
		
// CONSTRUCTEUR
		Polygone();
		
};

#endif
