#define PORT 21
#define TAILLEMAXLIGNE 1024

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

#define FATAL(err){ perror((char *)err); exit(1); }

int connexion(char *, int);  
char *lireligne(FILE *, char *);
void ecrireligne(FILE *, char *);
void travail(FILE *, FILE *);

/* nom de la machine interrogee, nom de l'utilisateur et son mot de passe */
char *hostname,*username,*password;
int port1, port2;

/* variable permettant d'activer (1) ou non (0) le mode verbose */
int VERBOSE = 0;

/* --------------------------------------------------------- */
int main(int argc, char * argv[]) 
{
	int fd, c;
	FILE *in, *out;
	
	/* gestion des options : -v ou -h */	
	while ((c=getopt(argc, argv, "vh")) != -1)
		switch (c)
		{
			case 'v':
				VERBOSE = 1;
				break;
			case 'h':
				printf("usage:  aftp [-vh] [serveur] [file]\n");
				exit(0);
				break;
			default:
				printf("option inconnue\n");
				exit(0);
				break;
		};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~

	hostname = "ftp.lip6.fr";
	if (VERBOSE) printf("     POPHOST = %s\n",hostname);

	username = "ftp"; 
	if (VERBOSE) printf("     POPUSER = %s\n",username);

	password ="ftp"; 

// ouverture de la connexion */
	fd=connexion(hostname,PORT);

// Ouverture de fichiers de haut niveau (cf. polycop systeme) */
	in  = fdopen(fd,"r");
	out = fdopen(fd,"w");

// travail
	travail(in,out);
	
	ecrireligne(out, "QUIT");

	close(fd);
	exit(0);
}

///####################################################################################
///####################################################################################

/* --------------------------------------------------------- */
/* fonction connexion
   Ouvre la connexion vers un port d'un serveur.
   Retourne la socket ouverte
   Exit en cas d'echec
   */

int connexion(char *hostname, int port)  
{
	int fdPort;
	struct sockaddr_in addr_serveur;
	socklen_t lg_addr_serveur = sizeof addr_serveur;
	struct hostent *serveur;

	/* creation de la prise */
	fdPort=socket(AF_INET,SOCK_STREAM,0);
	if (fdPort<0)
		FATAL("socket");

	/* recherche de la machine serveur */
	serveur = gethostbyname(hostname);
	if (serveur == NULL)
		FATAL("gethostbyname");

	/* remplissage adresse socket du serveur */
	addr_serveur.sin_family      = AF_INET;
	addr_serveur.sin_port        = htons(port);
	addr_serveur.sin_addr        = *(struct in_addr *) serveur->h_addr;

	/* demande de connexion au serveur */
	if ( connect(fdPort,(struct sockaddr *)&addr_serveur, lg_addr_serveur) < 0 )
		FATAL("connect");

	return fdPort;
}


/* --------------------------------------------------------- */
/* fonction travail
   Effectue le dialogue avec le serveur 
   à travers les flots in et out 
   */

char *lireligne(FILE *in, char ligne[])
{
	char *p;
	p = fgets(ligne,TAILLEMAXLIGNE,in);
		if (VERBOSE)
	printf("     recu  >> %s",ligne);
	return p;
}

void ecrireligne(FILE *out, char ligne[])
{
	if (VERBOSE)
		printf("     envoi << %s\n",ligne);
	fprintf(out,"%s\r\n",ligne);
	fflush(out);
}

void travail(FILE *in, FILE *out)
{ 
	char ligne[TAILLEMAXLIGNE];
	char tampon[TAILLEMAXLIGNE];
	//int nombre_de_messages, taille_boite;

	/* reception banniere */
	lireligne(in,ligne);
	do{ lireligne(in,ligne);}
	while( ligne[0] != '2' );
	
	if(ligne[0] != '2')
	{
		printf("Pas de banniere. Abandon\n");
		exit(1);
	};

	sprintf(tampon,"user %s", username);
	ecrireligne(out, tampon);
	lireligne(in, ligne);
	if(ligne[0] != '3')
	{
		printf("Erreur d'identification pour %s\n", username);
		exit(1);
	};
	
	sprintf(tampon,"pass %s", password);
	ecrireligne(out, tampon);
	lireligne(in, ligne);
	if(ligne[0] != '2')
	{
		printf("Erreur de mot de passe pour %s\n", password);
		exit(1);
	};
	do{ lireligne(in,ligne);}
	while( ligne[0] != '2' );
	
	sprintf(tampon,"pasv");
	ecrireligne(out, tampon);
	lireligne(in, ligne);
	if(ligne[0] != '2')
	{
		printf("Erreur de commande PASV\n");
		exit(1);
	};
	printf("%s",ligne);
	
	// 227 Entering Passive Mode (195,83,118,1,211,136)
}

