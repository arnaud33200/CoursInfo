// fichier Oeuvre.h

#ifndef OEUVRE_H
#define OEUVRE_H

#include <string>
#include "Date.h"

using namespace std;

class Oeuvre : public Date
{
	public:
 	  	Oeuvre( string aut, string titre, string sty,
           		int j, int m, int a, int val );
        Oeuvre( const Oeuvre & o );
 	  	virtual ~Oeuvre();
 	  	virtual string toString() const;
 	  	
	private:
   		string my_auteur;
   		string my_titre;
   		string my_style;
   		Date my_date_creation;  // date de creation 
  		int my_valest;
  		
};

#endif // #ifndef OEUVRE_H

