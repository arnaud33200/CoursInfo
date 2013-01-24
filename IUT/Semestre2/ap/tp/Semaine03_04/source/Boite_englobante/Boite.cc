// Fichier Boite.cc

#include<iostream>
#include<cstdlib>
#include<sstream>
#include<string>
#include<cmath>

#include "Boite.h"

using namespace std;


Boite::Boite( const Point & p )
{
	cout << "BOITE :: constructeur avec 1 point" << endl;
	my_points = new Point[5];
	my_points[0] = p;
	my_bas_gauche = p;
	my_haut_droite = p;
	my_nb_alloues = 1;
	my_nb_points = 5;
}

Boite::~Boite()
{
	delete[] my_points;
}

void Boite::affiche() const
{
	cout << endl << "#########################################################" << endl << endl;
	cout << "la boite à " << my_nb_alloues << " points alloues :" << endl;
	for ( int i=0; i<my_nb_alloues; i++ )
		cout << "( " << my_points[i].getX() << " | " << my_points[i].getY() << " ) - ";
	cout << endl << endl << "coordonnees du cadre : " << endl;
	cout << "bas gauche : ( " << my_bas_gauche.getX() << " | " << my_bas_gauche.getY() << " )" << endl;
	cout << "haut droite : ( " << my_haut_droite.getX() << " | " << my_haut_droite.getY() << " )" << endl;
	cout << endl << "la boite peut contenir encore " << my_nb_points - my_nb_alloues << " points" << endl;
}

bool Boite::interieur( const Point & p ) const
{
	if ( p.getX() > my_bas_gauche.getX() && p.getX() < my_haut_droite.getX() )
	{
		if ( p.getY() > my_bas_gauche.getY() && p.getY() < my_haut_droite.getY() )
			return 1;
	}
	return 0;
}

void Boite::agrandir()
{
	Point* p = new Point[my_nb_points*2];
	
	for ( int i=0; i<my_nb_points; i++ )
	{
		p[i].setX( my_points[i].getX() );
		p[i].setY( my_points[i].getY() );
	}
	
	delete[] my_points;
	my_points = p;
	my_nb_points*=2;
	delete[] p;	
}

void Boite::ajouterPoint( const Point & p )
{
	if ( my_nb_alloues == my_nb_points )
			agrandir();
		
	my_points[my_nb_alloues].setX( p.getX() );
	my_points[my_nb_alloues].setY( p.getY() );
	my_nb_alloues++;
		
	if ( not interieur(p) )
	{
		if ( p.getX() < my_bas_gauche.getX() ) my_bas_gauche.setX( p.getX() );
		else if ( p.getX() > my_haut_droite.getX() ) my_haut_droite.setX( p.getX() );
		
		if ( p.getY() < my_bas_gauche.getY() ) my_bas_gauche.setY( p.getY() );
		else if ( p.getY() > my_haut_droite.getY() ) my_haut_droite.setY( p.getY() );
	}			
}

void Boite::supprimerPoint( const Point & p )
{
	bool bon = 0;
	int i=0;
	
// si le point existe dans la boite
	while ( i < my_nb_alloues && not bon )
	{
		if ( p == my_points[i] )
				bon = 1;
		i++;
	}
	
	if ( bon )
	{
		my_nb_alloues-=1;
		
	}
	else
	{
		cout << "le point n'est pas présent dans la boite ! " << endl;
	}	
}
