#include <stdio.h>
#include <stdlib.h>

int main()
{
	int * tab = malloc(sizeof(int)*5);
	int * p = &tab[3];
	*p = 5;
	printf("val : %i\n", tab[3]);

	return 0;
}
