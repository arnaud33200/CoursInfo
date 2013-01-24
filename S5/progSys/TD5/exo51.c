#define _XOPEN_SOURCE 600

#include <signal.h>
#include <stdio.h>

struct sigaction old;

void handlerView(int a)
{
	printf("CTRL - C\n");
		sigaction(a, &old, NULL);
}

int main()
{
	struct sigaction myact;
	myact.sa_handler = handlerView;
	sigemptyset(&myact.sa_mask);
	myact.sa_flags = SA_RESETHAND;
	
	sigaction(SIGINT, &myact, &old);
	while ( 1 == 1 );
	return 0;
}
