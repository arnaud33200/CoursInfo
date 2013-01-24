/*----------------------------------------------------------------
 annee II
                  Cours systeme d'exploitation

Illustration des interruptions
------------------------------
Questions:
      a)  Que fait ce programme?
      b)  Compiler et executer le programme.
      
-----------------------------------------------------------------*/
#include <unistd.h> 
#include <signal.h>
void interruption (), arret ();

char cmpt = '1';

int main ()
{

  	signal(SIGINT, interruption);  /*  recuperation de ^C  */
  	signal(SIGQUIT, arret);        /*  recuperation de ^\  */
  	signal(SIGTSTP, SIG_IGN);      /*  on ignore ^z        */

	for (;;) {
		write(1,&cmpt,1);
		sleep(1);
	}
}

void arret () {

	write (1,"\n",1);
        write (1,"Au revoir\n",10);
	signal(SIGQUIT, SIG_DFL);
        _exit(0);
}

void interruption () {

        signal(SIGINT, interruption);	
	cmpt++;
}
