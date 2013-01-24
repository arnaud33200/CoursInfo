#include <stdio.h>

int main()
{
	int i=0;
	for (i; i<100; i++)
	{
		if ( i%5 == 0 )
			printf("PING ");
		if ( i%3 == 0 )
			printf("PONG ");
		printf("\n");
	}

	return 0;
}
