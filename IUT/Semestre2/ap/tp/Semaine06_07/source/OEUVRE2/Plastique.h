#ifndef PLASTIQUE_H
#define PLASTIQUE_H

#include <string>

#include "Oeuvre.h"
#include "Date.h"

using namespace std;

class Plastique : public Oeuvre
{
	private:
		string my_appart;
		Date my_change;
		string my_materiaux;
		
	public:
		Plastique( string aut, string t, string s, int j, int m, int a,
					int v, string ap, int cj, int cm, int ca, string mat );
		Plastique( const Plastique & p );
		~Plastique();
		
		string toString() const;
};



#endif
