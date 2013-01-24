///////////////////////////////////////////////////////////////////////////////
// token.cc
///////////////////////////////////////////////////////////////////////////////

#include "token.h"

string nextArg( const string & expression, int & index)
{
  bool num, point;
  char c;

  int i = index;
  int max = expression.length();
  bool blanc = true;
  string arg = "";

  // Se repositionne sur la bonne partie de l'expression.
  while ( ( i < max ) && blanc )
    {
      if ( ( expression[ i ] != ' ' )       // espace
	   && ( expression[ i ] != '\t' ) ) // tabulation
	blanc = false;
      else 
	i++;
    } // while ( ( i < max ) && blanc )

  // Analyse cette partie.
  if ( ! blanc )
    {
      c = expression[ i ];
      arg = arg + c;
      i++;
      if ( isdigit( c ) )
	{
	  num = true;
	  point = false;
	  while ( ( i < max ) && num )
	    {
	      c = expression[ i ];
	      if ( isdigit( c ) )
		{
		  arg = arg+c;
		  i++;
		}
	      else
		{
		  if ( ( c == '.' ) && ( ! point ) )
		    {
		      point = true;
		      arg = arg + c;
		      i++;
		    }
		  else
		    num = false;
		}
	    } // while ( ( i < max ) && num )
	} // if ( isdigit( c ) )
    } // if ( ! blanc )
  index = i;
  
  return arg;
}

