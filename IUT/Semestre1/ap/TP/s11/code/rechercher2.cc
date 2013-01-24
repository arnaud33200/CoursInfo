#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

#include "change.hh"

int main( int argc, char* argv[] )
{
  string mot, s, a;
  int n1;

  if( argc < 4 ) {
    cout << "Erreur : il manque des arguments." << endl;
    cout << "Usage : " << argv[0] << " mot s" << endl;
    exit(-1);
  }

  mot = argv[1];
  s  = argv[2];
  a = argv[3];
  
changeword(mot, s, a);

  //~ n1 = mot.find( s );
//~ 
  //~ if( n1 == string::npos )
    //~ cout << s << " pas trouvé dans " << mot << endl;
  //~ else
    //~ cout << s << " trouvé dans " << mot << " à la position " << n1 << endl;
  //~ 
  return EXIT_SUCCESS;
}


