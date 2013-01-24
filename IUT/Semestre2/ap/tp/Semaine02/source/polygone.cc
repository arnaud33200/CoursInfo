#include<iostream>
#include<cstdlib>
#include<sstream>
#include<string>
#include<cmath>

#include "polygone.h"
#include "point.h"

using namespace std;


void Polygone::saisie()
{
	float val;
	
	do
	{
		if ( my_taille > MAX )
			cout << "taille trop grande !" << endl;
		cout << "saisissez le nombre de point ( <= 10 ) : "; cin >> my_taille;
	}
	while ( my_taille > 10 );

	for ( int i=0; i < my_taille; i++ )
	{
		cout << endl<< "point numero " << i+1 << " : " << endl;
		cout << "	- abcisse : "; cin >> val;
			 my_tab[i].setX(val);
		cout << "	- ordonne : "; cin >> val;
		my_tab[i].setY(val);
	}
}

string Polygone::toString()
{
	ostringstream o;
	for ( int i=0; i<my_taille; i++ )
	{
		o << "( " << my_tab[i].getX() << " , " << my_tab[i].getY() << " )" << endl;
	}
	
  return o.str();
}

void Polygone::deplace(const float &dx, const float &dy)
{
	for ( int i=0; i<my_taille; i++)
	{
		my_tab[i].setX( my_tab[i].getX() + dx );
		my_tab[i].setY( my_tab[i].getY() + dy );
	}
}

void Polygone::ajoutSommet(const Point &p)
{
	if ( my_taille != MAX )
	{
		my_tab[my_taille].setX( p.getX() );
		my_tab[my_taille].setY( p.getY() );
		my_taille++;
	}
	else
		cout << "taille deja au maximum ! " << endl;	
}

float Polygone::perimetre() const
{
	float p=0;
	for (int i=0; i<my_taille; i++ )
	{
		p += sqrt( my_tab[i].getX()*my_tab[i].getX() + my_tab[i].getY()*my_tab[i].getY() );
	}
	return p;
}


// ############ ACCESSEURS #################

int Polygone::getT() const
{
	return my_taille;
}

void Polygone::setT(const int &t)
{
	my_taille = t;
}


// ########### CONSTRUCTEUR #################

Polygone::Polygone()
{
	setT(0);
}
