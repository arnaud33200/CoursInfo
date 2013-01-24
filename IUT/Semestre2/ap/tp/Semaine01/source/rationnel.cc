#include<iostream>
#include<cstdlib>

#include "rationnel.h"

using namespace std;

/// ########### les methodes ################### ///

void Rationnel::affiche() const
{
	cout << my_num << " / " << my_deno << endl;
}

void Rationnel::transforme()
{
	setNum( getNum() + getDeno() );
	setDeno( getNum() - getDeno() );
	setNum( getNum() - getDeno() );
}

bool Rationnel::egalite( Rationnel p)
{
	if ( getNum()/getDeno() == p.getNum()/p.getDeno() )
		{
			cout << "les deux rationnels sont egaux" << endl;
			return 1;
		}
	else
	{
		cout << "les deux rationnels ne sont pas egaux" << endl;
		return 0;
	}
}



void Rationnel::addition(Rationnel p, Rationnel & resultat)
{
	if ( getDeno() != p.getDeno() )
	{
		resultat.setNum( (getNum() * p.getDeno()) + (p.getNum() * getDeno()) );
		resultat.setDeno( p.getDeno() * getDeno() );
	}
	else
	{
		resultat.setDeno( getDeno() );
		resultat.setNum( getNum() + p.getNum() );
	}
}

void Rationnel::soustraction(Rationnel p, Rationnel & resultat)
{
	if ( getDeno() != p.getDeno() )
	{
		resultat.setNum( (getNum() * p.getDeno()) - (p.getNum() * getDeno()) );
		resultat.setDeno( p.getDeno() * getDeno() );
	}
	else
	{
		resultat.setDeno( getDeno() );
		resultat.setNum( getNum() + p.getNum() );
	}
}

void Rationnel::multiplication(Rationnel p, Rationnel & resultat)
{
	resultat.setNum( getNum() * p.getNum() );
	resultat.setDeno( getDeno() * p.getDeno() );
}

void Rationnel::division(Rationnel p, Rationnel & resultat)
{
	p.transforme();
	multiplication(p,resultat);
}	

void Rationnel::reducteur()
{
	int n = pgcdrationnel( getDeno(), getNum() );
	setNum(getNum()/n);
	setDeno(getDeno()/n);
}

/// ########### les constructeurs ############# ///

Rationnel::Rationnel()
{ 
	setDeno(0);
	setNum(1);
}

Rationnel::Rationnel( int n, int d )
{
	setNum(n);
	setDeno(d);
}

/// ########### les accesseurs ############### ///

void Rationnel::setNum( int n )
{
	my_num = n;
}

void Rationnel::setDeno(int d )
{
	my_deno = d;
}

int Rationnel::getDeno() 
{
	return my_deno;
}

int Rationnel::getNum() 
{
	return my_num;
}
