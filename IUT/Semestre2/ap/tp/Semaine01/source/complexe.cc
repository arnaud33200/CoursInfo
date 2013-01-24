#include<iostream>
#include<cstdlib>

#include "complexe.h"

using namespace std;

/// ########### les accesseurs ################# ///	

int Complexe::getRe()
{
	return my_re;
}

int Complexe::getIm()
{
	return my_im;
}

void Complexe::setRe(int r)
{
	my_re = r;
}

void Complexe::setIm(int i)
{
	my_im = i;
}

/// ########### les constructeur ############### ///	
		
Complexe::Complexe()
{
	setRe( 0 );
	setIm( 0 );
// initialisation à 0
}

Complexe::Complexe(int r, int i)
{
	setRe( r );
	setIm( i );
}

/// ########### les methodes ################### ///	

void Complexe::afficher()
{
	cout << getRe() << " + i" << getIm() << endl;
}


void Complexe::addition( Complexe c, Complexe & r )
{
	r.setRe( getRe() + c.getRe() );
	r.setIm( getIm() + c.getIm() );
}
	
void Complexe::soustraire( Complexe c, Complexe & r )
{
	r.setRe( getRe() - c.getRe() );
	r.setIm( getIm() - c.getIm() );
}

void Complexe::multiplier( Complexe c, Complexe & r )
{
	r.setRe( (getRe()*c.getRe()) - (getIm()*c.getIm()) );
	r.setIm( (getRe()*c.getIm()) + (getIm()*c.getRe()) );
}

