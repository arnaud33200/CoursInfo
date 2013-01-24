#include <stdio.h>

int grille[3][3];
int iblank, jblank;		// indique les coordonnés ou la case est vide

int rand_a_b(int a, int b);
int estpresent( int v );
int esttermine();
int deplaceblock( int ib, int jb);
int deplaceid(int v);
void xchange(int* a, int* b);
void afficher();

int main ( int argc , char ** argv )
{
	srand(time(NULL));
	int i, j;
	int val;
	
	for( i=0; i<3; i++)
		for( j=0; j<3; j++ )
			grille[i][j] = -1;
	
	for( i=0; i<3; i++)
	{
		for( j=0; j<3; j++ )
		{
			val=rand_a_b(0,8);
			while( estpresent(val) == 1)
				val=rand_a_b(0,9);
			grille[i][j] = val;
			
			if ( grille[i][j] == 0 )
			{
				iblank = i;
				jblank = j;
				printf("  ");
			}
			else printf("%d ", grille[i][j] );
		}
		printf("\n");
	}
	printf("\nCoordonné du vide : %d - %d\n", iblank, jblank);
	
	//~ grille={{1,0,2},{3,4,5},{6,7,8}};
	iblank=0;
	jblank=1;
	
	while( esttermine() == 0 )
	{
		printf("\nvaleur à déplacer ? : \n");
		scanf("%d",&i);
		deplaceid(i);
	}
	
	return 1;
}

int rand_a_b(int a, int b)
{ return rand()%(b-a) +a; }

int estpresent( int v )
{
	int i=0, j=0;
	int trouve=0;
	while( i< 3 && trouve == 0 )
	{
		j=0;
		while( j< 3 && trouve == 0 )
		{
			if( grille[i][j] == v )
				trouve=1;
			j++;
		}
		i++;
	}
	return trouve;
}

int esttermine()
{
	int i=0, j=0;
	int bon=1;
	while( i< 3 && bon == 1 )
	{
		j=0;
		while( j< 3 && bon == 1 )
		{
			if( grille[i][j] != (3*i)+j )
				bon=0;
			j++;
		}
		i++;
	}
	return bon;
}

int deplaceblock( int ib, int jb)
{
	int trouve=0;
 if((ib==iblank && jb==jblank+1 && jblank+1>=0 && jblank+1<3)
||(ib==iblank && jb==jblank-1 && jblank-1>=0 && jblank-1<3)
||(ib==iblank+1 && jb==jblank && iblank+1>=0 && iblank+1<3)
||(ib==iblank-1 && jb==jblank && iblank-1>=0 && iblank-1<3) )
		trouve=1;
		
	if( trouve == 1 )
	{
		grille[iblank][jblank] = grille[ib][jb];
		grille[ib][jb] = 0;
		xchange(&ib, &iblank);
		xchange(&jb, &jblank);	
		afficher();	
	}
	else
		printf("la piece %d-%d est pas a proximite de la case vide\n", ib, jb);	
		
	return trouve;
}

int deplaceid(int v)
{
	if( v>=0 && v<9 )
	{
		int i=0, j=0;
		int trouve=0;
		while( i< 3 && trouve == 0 )
		{
			j=0;
			while( j< 3 && trouve == 0 )
			{
				if( grille[i][j] == v )
					trouve=1;
				else
					j++;
			}
			if( trouve == 0 )
				i++;
		}
		return deplaceblock(i,j);
	}
	else
	{
		printf("valeur inexistant\n");
		return 0;
	}
}

void xchange(int* a, int* b)
{
	*a = *a+*b;
	*b = *a-*b;
	*a = *a-*b;
}

void afficher()
{
	printf("\n");
	int i,j;
	for( i=0; i<3; i++)
	{
		for( j=0; j<3; j++ )
		{
			if( grille[i][j] != 0 )
				printf("%d ", grille[i][j] );
			else
				printf("  ");
		}
		printf("\n");
	}
}
