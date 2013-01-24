#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "change.hh"

void changeword (string &mot, string m1, string m2 ) 
{
	int n1 = mot.find ( m1 );
	int n2;

	if( n1 != string::npos )
	{
		while (n1 > 0)
		{
 			mot.erase( n1, m1.size() );
 			mot.insert(n1, m2);
 			n2 = mot.find ( m1, n1+m2.size() );
 			n1 = n2;
		}
	}
	else
		cout << "mot pas trouvé" << endl;
		
	cout << mot << endl;
	
}
