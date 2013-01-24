#ifndef ECRIT_H
#define ECRIT_H

#include <string>
#include "Oeuvre.h"
#include "Date.h"

using namespace std;

class Ecrit : public Oeuvre
{
	private:
		string my_langue;
		string my_theme;
		string my_edition;
		Date my_edit;
		
	public:
		Ecrit(string aut, string ti, string sty, int j, int m, int a, int val,
				string lan, string th, string ed, int dj, int dm, int da);
		Ecrit(const Ecrit & e);
		~Ecrit();
		string toString() const;  
};

#endif
