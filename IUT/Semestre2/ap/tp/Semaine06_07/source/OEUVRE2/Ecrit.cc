#include <iostream>
#include <string>

#include "Oeuvre.h"
#include "Date.h"
#include "util.h"
#include "Ecrit.h"

using namespace std;

Ecrit::Ecrit(string aut, string ti, string sty, int j, int m, int a, int val,
				string lan, string th, string ed, int dj, int dm, int da)
: Oeuvre(aut, ti, sty, j, m, a, val),
my_edit(dj, dm, da)
{
	my_langue = lan;
	my_theme = th;
	my_editeur = ed;
}

Ecrit::Ecrit(const Ecrit & e)
: Oeuvre e, my_edit(e.my_edit)
{
	my_langue = e.my_langue;
	my_theme = e.my_theme;
	my_editeur = e.my_editeur;
}
