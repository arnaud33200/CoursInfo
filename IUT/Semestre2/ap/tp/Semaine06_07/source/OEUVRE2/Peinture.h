// fichier Peinture.h

#ifndef PEINTURE_H
#define PEINTURE_H

#include <string>
#include "Date.h"
#include "Oeuvre.h" // declarons la classe de base

using namespace std;

class Peinture : public Oeuvre 
{   // heritage ...
	private:                           // ajoutons de nouveaux elements
   		string my_possesseur;
   		Date my_date_acquis;  		   // date d'acquisition
   		string my_support;
   		string my_matiere;
   		
	public:
   		Peinture( string artiste, string titre, string sty,
         		    int j, int m, int a, int val,
            		string poss, int ja, int ma, int aa, string sup, string mat );
		Peinture( const Peinture & p );
   		~Peinture();
   		string toString() const;           // renseignons nous sur la peinture...
};

#endif // #ifndef PEINTURE_H

