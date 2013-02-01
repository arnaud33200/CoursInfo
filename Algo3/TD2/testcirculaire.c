
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int * tab = malloc(sizeof(int)*5);
	tab[0] = 4;
	tab[1] = 6;
	tab[2] = 8;
	tab[3] = 2;
	tab[4] = *tab[0];
	
	int i;
	for (i=0; i<10; i++)
	{
		tab++;
		printf("- %i\n", *tab);
	}
	
	return 0;
}

