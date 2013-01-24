int triangle( int * f, int * s, int i, int j );
/*{
  if ( i == 1 )
    return 1;

  int a, b, c;
  int *tmp;

  for ( a=0; a<i; i++ )
    f[a] = 0;
  f[0] = 1;
  f[1] = 1;

  for ( b=0; b<j; b++ )
    {
      for ( a=1; a<i; a++ )
	  s[a] = f[a-1] + f[a];
      tmp = f;
      f = s;
      s = tmp;
    }
  return f[i];
}*/

int main()
{
	int first[5];
	int second[5];
	int resultat = triangle( first, second, 3, 4);
	printf("resulta de la colonne 3 ligne 4 : %d \n", resultat );
	
	return 0;
}
