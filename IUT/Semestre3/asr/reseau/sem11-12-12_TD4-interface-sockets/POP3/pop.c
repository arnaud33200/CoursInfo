/*  Client pop3 */

/* usage: export POPHOST=boite ou pop
          export POPUSER=login
          export POPPWD=.....
   puis
          pop [-vh] */

/* Le numero de port de pop3 */
#define PORT 110

/* Taille maximale d'une ligne recue de pop3 */
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

#define FATAL(err) { perror((char *)err); exit(1); }

int connexion(char *, int);  
char *lireligne(FILE *, char *);
void ecrireligne(FILE *, char *);
void travail(FILE *, FILE *);

void affichermessage( FILE *, FILE *, int );
void afficherexpsujet( FILE *, FILE *, int );
void afficherexpsujetall( FILE * in, FILE * out);
void supprimermessage( FILE * in, FILE * out, int n );
void verifconnect( FILE * in, FILE * out);

/* nom de la machine interrogee, nom de l'utilisateur et son mot de passe */
char *hostname,*username,*password;

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
				printf("usage: export POPHOST=boite ou pop\n"
					 "       export POPUSER=login\n"
					 "       export POPPWD=.....\n"
					 "puis\n"
					 "       pop [-vh]\n");
				exit(0);
				break;
			default:
				printf("option inconnue\n");
				exit(0);
				break;
		};


/***********************************************************************
 * RECUPERATION DES VARIABLE POUR LA CONNEXION
***********************************************************************/

	/* nom de la machine interrogee, nom de l'utilisateur et son mot de passe */
	/* recuperes dans l'environnement */
	hostname = getenv("POPHOST");
	if (hostname==NULL) hostname = "pop.free.fr"; //hostname = getenv("HOSTNAME");
	if (hostname==NULL)
	{
		fprintf(stderr,"* Définir le nom de machine dans la variable POPHOST\n");
		exit(1);
	}
	if (VERBOSE)
		printf("     POPHOST = %s\n",hostname);

	username = getenv("POPUSER");
	if (username==NULL)  username = "mstinfo1"; //username = getenv("LOGNAME");
	if (username==NULL)
	{
		fprintf(stderr,"* Définir le nom de l'utilisateur dans la variable POPUSER\n");
		exit(1);
	}
	if (VERBOSE)
		printf("     POPUSER = %s\n",username);

	password ="master"; //password = getenv("POPPWD");
	if(password == NULL)
	{
		fprintf(stderr,"* Définir le mot de passe dans la variable POPPWD\n");
		exit(1);
	}

	/* ouverture de la connexion */
	fd=connexion(hostname,PORT);

	/* Ouverture de fichiers de haut niveau (cf. polycop systeme) */
	in  = fdopen(fd,"r");
	out = fdopen(fd,"w");

	/* travail */
	travail(in,out);

	int reponse;
	

	while ( 1 == 1 )
	{
		printf("\n\n");
		verifconnect(in, out);
			
		printf("quelle action voulez vous effectuer ?\n\n");
		printf("\t1 : afficher un message ?\n");
		printf("\t2 : afficher expediteur et sujet ?\n");
		printf("\t3 : afficher expediteur et sujet de tous les messages ?\n");
		printf("\t4 : supprimer un message ?\n");
		printf("\t5 : quitter ?\n");

		printf("\n\nreponse : ");
		scanf("%d", &reponse);
		switch ( reponse )
		{
			case 1:
			{
				printf("\nquelle numero de message ? : ");
				scanf("%d", &reponse);
				affichermessage( in, out, reponse );
				break;
			}
			case 2:
			{
				printf("\nquelle numero de message ? : ");
				scanf("%d", &reponse);
				afficherexpsujet( in, out, reponse );
				break;
			}
			case 3:
			{
				afficherexpsujetall(in, out);
				break;
			}
			case 4:
			{
				printf("\nquelle numero de message ? : ");
				scanf("%d", &reponse);
				supprimermessage(in, out, reponse);
				break;
			}
			case 5:
			{
				exit(0);
				break;
			}
			//defaut: printf("valeur inconnue");
		}
	}
	
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
	if (connect(fdPort,(struct sockaddr *)&addr_serveur, lg_addr_serveur) < 0)
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
	if(ligne[0] != '+')
	{
		printf("Pas de banniere. Abandon\n");
		exit(1);
	};

	/* envoi identification */
	sprintf(tampon,"USER %s", username);
	ecrireligne(out,tampon);

	lireligne(in,ligne);
	if(ligne[0] != '+')
	{
		printf("USER rejeté. Abandon\n");
		exit(1);
	};

	/* envoi mot de passe */
	sprintf(tampon,"PASS %s", password);
	ecrireligne(out,tampon);

	lireligne(in,ligne);
	if(ligne[0] != '+') 
	{
		printf("PASS rejeté. Abandon\n");
		exit(1);
	};

	/* La reponse precedente contient souvent le nombre de messages
	 de la boite, mais elle n'est pas tres precise dans la RFC,
	 et donc differe selon les versions de service POP3.
	 Pour recuperer le nombre de messages de maniere fiable,
	 utiliser la commande STAT */
/**
// envoi STAT pour recuperer nb messages 
	sprintf(tampon,"STAT");
	ecrireligne(out,tampon);

// reception de +OK n mm 
	lireligne(in,ligne);
	sscanf(ligne+3,"%d %d", &nombre_de_messages, &taille_boite);

	printf("Il y a %d messages dans la boite.\n",nombre_de_messages);
	printf("La taille totale est de %d octets.\n",taille_boite);

// fermeture
	ecrireligne(out,"QUIT");

	lireligne(in,ligne);
**/
}

void affichermessage( FILE * in, FILE * out, int n )
{
	if( n > 0 )
	{
		char ligne[TAILLEMAXLIGNE];
  		char tampon[TAILLEMAXLIGNE];
  		int trouve = 0;
  		int eof = 0;
  		
  		sprintf(tampon,"TOP %d", n );
		ecrireligne(out,tampon);
  		
  		printf("\n~~~~~~~~~~~~~~~~~~~~~~~DEBUT\n\n");
  		
  		while ( eof == 0 )
  		{
			lireligne(in, ligne);
			sscanf(ligne,"%s %s", tampon, tampon);
			if( trouve == 0 && strncmp(tampon, "text/plain", 10) == 0 )
			{
				trouve = 1;
				lireligne(in, ligne);
			}
			else if( trouve == 1 && strncmp(tampon, "text/html", 9) == 0 )
			{
				trouve = 2;
				
			}
			
			if( trouve == 1 )
				printf("%s", ligne);
				
			if( ligne[0] == '.' && ligne[1] != '.' )
				eof = 1;
		}
		
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FIN\n");

	}
}

void afficherexpsujet( FILE * in, FILE * out, int n )
{
	char ligne[TAILLEMAXLIGNE];
	char tampon[TAILLEMAXLIGNE];
	int nbmess;
	
	sprintf(tampon,"STAT");
	ecrireligne(out,tampon);
	lireligne(in,ligne);
	sscanf(ligne,"%s %d %s", tampon, &nbmess, tampon);
	
	if( n >= 1 && n<= nbmess )
	{  	
		if (VERBOSE)
			printf("     affichage du message n°%d\n",n);
  		int eof = 0;
  		
  		sprintf(tampon,"TOP %d", n );
		ecrireligne(out,tampon);
  		
		while( eof == 0 )
		{
			lireligne(in, ligne);
			sscanf(ligne,"%s", tampon);
			if ( strncmp(tampon	, "Subject", 7 ) == 0 )
			{
				printf("%s", ligne);
				lireligne(in, ligne);
				printf("%s\n", ligne);
				
			}
				
			//~ printf("### %s\n", ligne);
			
			if( ligne[0] == '.' && ligne[1] != '.' )
				eof = 1;
		}
		
	}
	else
		{
			printf("ERROR : message %d est inexistant !\n\n", n);
		}
}

void afficherexpsujetall( FILE * in, FILE * out)
{

	char ligne[TAILLEMAXLIGNE];
	char tampon[TAILLEMAXLIGNE];
	int nbmess = 0;
	int i;
	
// connaitre le nombre de message
	sprintf(tampon,"STAT");
	ecrireligne(out,tampon);
	lireligne(in,ligne);
	sscanf(ligne,"%s %d %s", tampon, &nbmess, tampon);
	printf("nombre de message : %d \n\n", nbmess);
	
	for( i=1; i<=nbmess; i++)
	{
		printf("Message N°%d : \n\n", i);
		afficherexpsujet(in, out, i); 
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	}
}

void supprimermessage( FILE * in, FILE * out, int n )
{
	char ligne[TAILLEMAXLIGNE];
	char tampon[TAILLEMAXLIGNE];
	int nbmess;
	
	sprintf(tampon,"STAT");
	ecrireligne(out,tampon);
	lireligne(in,ligne);
	sscanf(ligne,"%s %d %s", tampon, &nbmess, tampon);
	
	if( n >= 1 && n<= nbmess )
	{  	
		sprintf(tampon,"DELE %d", n);
		ecrireligne(out,tampon);
		lireligne(in,ligne);
		if(ligne[0] != '+')
		{
			printf("echec de suppression\n");
			exit(1);
		}
		if (VERBOSE)
			printf("le message %d a été supprimé", n);
	}
	else
	{
		printf("ERROR : message %d est inexistant !\n\n", n);
	}
}

void verifconnect( FILE * in, FILE * out )
{
	char ligne[TAILLEMAXLIGNE];
	char tampon[TAILLEMAXLIGNE];
	sprintf(tampon,"NOOP");
	ecrireligne(out, tampon);
	lireligne(in,ligne);
	if(ligne[0] != '+')
	{
		printf("Vous avez été déconnecté, reconnection en cours ...");
		connexion(hostname,PORT);
	}
}
