#include "tri.h"

TAdresse adrElemMedian( const Liste<Etudiant> & l, const TAdresse & a, const TAdresse & b )
{
	TAdresse adr, adrn;
	adr = adrn = a;
	while ( adr != b )
	{
		adr = l.adresseSuivant( adr );
		adrn = l.adresseSuivant( adrn );
		if ( adrn == b )
			return adr;
		else
			adrn = l.adresseSuivant( adrn );
	}
	return adr;
}

void fusion( Liste<Etudiant> & l, const TAdresse & m, const TAdresse & a, const TAdresse & b)
{
	TAdresse adra, adrb;
	adra = a; adrb = m;
	while ( adra != m && adrb != b )
	
}
