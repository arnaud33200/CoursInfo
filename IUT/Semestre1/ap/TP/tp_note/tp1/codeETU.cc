/*
#############################################
Nom de l'étudiant:	ladoucette					#
Prénom de l'étudiant:	arnaud					#
groupe : S1C''									#
Heure de passage : 11h17 							#
#############################################
*/


#include <iostream>
#include <cstdlib>

using namespace std;


//Répondez ici à la question 1

// 010111001000 une fois compressé devient ?
// 10111031201130

//513010112030 une fois décompressé devient ?
// 111110000100000

//Fin de réponse à la question 1



//Répondez ici à la question 2

const int TAILLE=100;
int p[TAILLE];

//Fin de réponse à la question 2



//Répondez ici à la question 3

void afficheMessage(int p[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout << p[i];
	}
	cout << endl;
}
//Fin de réponse à la question 3



//Répondez ici à la question 4

int saisirBinaire()
{
	int val;
	bool good=0;
	while ( good != 1 )
	{
		cout << "ecrivez un entier entre -1 et 1" << endl;
		cin >> val;
		if (val >= -1 && val <= 1)
			good=1;
	}
	return val;	
}
//Fin de réponse à la question 4




//Répondez ici à la question 5
void initMessageBinaire(int p[], int & size)
{
	int i=0;
	p[i]=0;
	while ( p[i] !=-1 && i<TAILLE)
	{
		p[i]=saisirBinaire();
		if (p[i] != -1)
			i++;
	}
	size=i;
}
//Fin de réponse à la question 5



//Répondez ici à la question 6
void compresser(int p[], int size, int pCompresse[],int &sizeCompresse)
{
int i=0;
int k=0;
int cpt;
while (i<size)
	{
	int val=p[i];
	cpt=0;
	int j=i+1;
	while (j<size && p[j]==val)
		{
		cpt++;
		j++;
		}
	i=j;
	pCompresse[k]=cpt+1;
	k++;
	pCompresse[k]=val;
	k++;
	}
sizeCompresse=k;
}
//Fin de réponse à la question 6



//Répondez ici à la question 7

void decompresser(int pCompresse[],int sizeCompresse, int pDecompresse[], int &sizeDecompresse)
{
	int id=0;
	sizeDecompresse=0;
	for (int i=0; i < (sizeCompresse-1); i+=2)
	{
		sizeDecompresse+=pCompresse[i];
		for (int j=0; j < pCompresse[i]; j++)
		{
			pDecompresse[id]=pCompresse[i+1];
			id++;
		}
	}
}

//Fin de réponse à la question 7



//Répondez ici à la question 8
/*
float calculCompression(int sizeDecompresse, int sizeCompresse)
{
	float TC=0;
	TC = sizeDecompresse.0 - sizeCompresse.0;
	TC = TC / sizeDecompresse.0 ;
	TC = TC * 100.0;
	return TC;
	
} 
*/
//Fin de réponse à la question 8



//Répondez ici à la question 9

//Une fois compressée, la chaine 1010101010 le taux de compression vaut -100 car ?????
// car si on le compresse ça donne 11101110111011101110
// donc la taille du message compresse est supérieur a la taille du message non compresse

//Fin de réponse à la question 9



//Répondez ici à la question 10

void crypter(int p[], int size, int clef[], int sizeClef)
{
	int ip=0;
	int ic;
	while ( ip < size )
	{
		ic=0;
		while ( ic < sizeClef && ip < size)
		{
			p[ip]=p[ip]-clef[ic];
			ip++;
			ic++;
		}
		
	}
}

//Fin de réponse à la question 10



//Répondez ici à la question 11
void decrypter(int p[], int size, int clef[], int sizeClef)
{
	int ip=0;
	int ic;
	while ( ip < size )
	{
		ic=0;
		while ( ic < sizeClef && ip < size )
		{
			p[ip]+=clef[ic];
			ip++;
			ic++;
		}
	}
}
//Fin de réponse à la question 11

int main()
{




//Testez votre réponse à la question 2 
//Pensez à commenter de nouveau cette zone pour pouvoir faire les tests des questions suivantes
/*
p[0]=0;
cout << p[0] << endl;
*/
//Fin de testez votre réponse à la question 2



//Testez votre réponse à la question 3
//Pensez à commenter de nouveau cette zone pour pouvoir faire les tests des questions suivantes
/*
p[0]=1;
p[1]=1;
p[2]=0;
p[3]=0;
p[4]=1;
int size=5;
afficheMessage(p,size);
*/
//Fin de testez votre réponse à la question 3


//Testez votre réponse à la question 4
//Pensez à commenter de nouveau cette zone pour pouvoir faire les tests des questions suivantes
/*
int val=saisirBinaire();
cout << val << endl;
*/
//Fin de testez votre réponse à la question 4


//Testez votre réponse à la question 5
//Pensez à commenter de nouveau cette zone pour pouvoir faire les tests des questions suivantes
/*
int size;
initMessageBinaire(p,size);
afficheMessage(p,size);
*/
//Fin de testez votre réponse à la question 5



//Testez votre réponse à la question 6
//Pensez à commenter de nouveau cette zone pour pouvoir faire les tests des questions suivantes
/*
int size;
int pCompresse[TAILLE];
int sizeCompresse;
initMessageBinaire(p,size);
afficheMessage(p,size);
compresser(p,size,pCompresse,sizeCompresse);
afficheMessage(pCompresse,sizeCompresse);
*/
//Fin de testez votre réponse à la question 6




//Testez votre réponse à la question 7
//Pensez à commenter de nouveau cette zone pour pouvoir faire les tests des questions suivantes
/*
int size;
int pCompresse[TAILLE];
int pDecompresse[TAILLE];
int sizeDecompresse;
int sizeCompresse;
initMessageBinaire(p,size);
afficheMessage(p,size);
compresser(p,size,pCompresse,sizeCompresse);
afficheMessage(pCompresse,sizeCompresse);
decompresser(pCompresse,sizeCompresse,pDecompresse,sizeDecompresse);
afficheMessage(pDecompresse,sizeDecompresse);
*/
//Fin de testez votre réponse à la question 7





//Testez votre réponse à la question 8
//Pensez à commenter de nouveau cette zone pour pouvoir faire les tests des questions suivantes
/*
int size;
int pCompresse[TAILLE];
int pDecompresse[TAILLE];
int sizeDecompresse;
int sizeCompresse;
initMessageBinaire(p,size);
afficheMessage(p,size);
compresser(p,size,pCompresse,sizeCompresse);
afficheMessage(pCompresse,sizeCompresse);
decompresser(pCompresse,sizeCompresse,pDecompresse,sizeDecompresse);
afficheMessage(pDecompresse,sizeDecompresse);
cout << "taux de compression= "<< calculCompression(sizeDecompresse,sizeCompresse) << endl;
*/
//Fin de testez votre réponse à la question 8









//Testez votre réponse à la question 10
/*
p[0]=5;
p[1]=6;
p[2]=7;
p[3]=2;
p[4]=7;
p[5]=4;
p[6]=3;
p[7]=5;
int clef[3]={2,5,3};
int size=8;
int tailleClef=3;
afficheMessage(p,size);
crypter(p,size,clef,tailleClef);
afficheMessage(p,size);
*/
//Fin de testez votre réponse à la question 10




//Testez votre réponse à la question 11

p[0]=5;
p[1]=6;
p[2]=7;
p[3]=2;
p[4]=7;
p[5]=4;
p[6]=3;
p[7]=5;
int clef[3]={2,5,3};
int size=8;
int tailleClef=3;
afficheMessage(p,size);
crypter(p,size,clef,tailleClef);
afficheMessage(p,size);
decrypter(p,size,clef,tailleClef);
afficheMessage(p,size);

//Fin de testez votre réponse à la question 11

return EXIT_SUCCESS;    
}
