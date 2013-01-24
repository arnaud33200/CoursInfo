#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// un sommet est numéroté est possède une couleur initialisé à 0
struct sommet
{ 
	int num, color;
	sommet() { color = 0; }
};

// une arête se fait entre deux sommet s1 et s2
struct arete { sommet s1,s2; };


bool buildGraph( arete[] );		// récupère la prochaine arête 
int couleurSommet( arete[], sommet );
int firstFit( arete[] );
int maximum( int, int );
bool saveFile( arete[] );

fstream fichier;
fstream save;
int nbArete;
int nbColor;

/**#####################################################################*/
/// 	Fonction Main
/**#####################################################################*/

int main( int argc, char *argv[])
{
// execution uniquement avec un fichier en argument
	if ( argc != 2 )
	{
		cout << "Fichier graphe manquant en argument" << endl
			<< "USE : color-graph [FILE] " << endl;
		exit(1);
	}
	
	nbColor = 1;
	fichier.open(argv[1], fstream::in);
	fichier >> nbArete;
	
// tableau d'arête : sommet 1, sommet 2, couleur
	arete graphe[nbArete];
	
	buildGraph( graphe );
	fichier.close();
	nbColor = firstFit( graphe );
	saveFile( graphe );

	return 0;
}

/**#####################################################################*/
/// 	Fonction Main
/**#####################################################################*/

int firstFit( arete g[] )
{
	int maxColor = 1;
	
	for ( int i=0; i<nbArete; i++ )
	{
		g[i].s1.color = couleurSommet( g, g[i].s1 );
		g[i].s2.color = couleurSommet( g, g[i].s2 );
		maxColor = maximum( maxColor, g[i].s1.color );
		maxColor = maximum( maxColor, g[i].s2.color );
	}
	return maxColor;
}

/**#####################################################################*/
/// 	Fonction Main
/**#####################################################################*/

int couleurSommet( arete g[], sommet s)
{
	if( s.color == 0 )
	{
		cout << "couleur " << s.color << " pour le sommet " << s.num << " déjà utilisé" << endl;
		return s.color;
	}
	
	int c = 1;
	int j;
	int * affecCouleur;
	
	for ( int i=0; i<nbArete; i++ )
		if ( g[i].s1.num == s.num || g[i].s2.num == s.num )
			c += 1;
			
	affecCouleur = new int[c];
	for ( int i=0; i<nbArete; i++ )
	{
		if ( g[i].s1.num == s.num ) j = g[i].s1.color;
		else if ( g[i].s2.num == s.num ) j = g[i].s2.color;
			
		if ( j != 0 ) affecCouleur[j-1] = 1;		
	}
	
	for ( int i=0; i<c; i++ )
	{
		if( affecCouleur[i] != 1 )
			return i+1;
	}
	
	delete[] affecCouleur;
	return 0;
}

/**#####################################################################*/
/// 	Fonction Main
/**#####################################################################*/

// construit le graphe dans un tableau
bool buildGraph( arete g[] )
{
	int i=0;
	while( i<nbArete )
	{
// sortie erreur si fichier incomplet
		if ( not fichier.good() )
		{
			cout << "le fichier manque de valeurs" << endl
				<< "nombre d'arete attendus : " << nbArete << endl;
			exit(2);
		}
		
		fichier >> g[i].s1.num;
		fichier >> g[i].s2.num;
		i++;
	}		
}

/**#####################################################################*/
/// 	Fonction Main
/**#####################################################################*/

bool saveFile( arete g[] )
{
	save.open("graph_color.sav", fstream::out);
	save << nbArete << endl << nbColor << endl;
	for ( int i=0; i<nbArete; i++ )
		save << g[i].s1.num << " " << g[i].s1.color << " "<< g[i].s2.num << " "<< g[i].s2.color << endl;
	save.close();
	return true;
}

int maximum( int a, int b )
{
	if ( a > b ) return a;
	else return b;
}
