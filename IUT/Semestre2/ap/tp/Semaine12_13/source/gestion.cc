///////////////////////////////////////////////////////////////////////////////
// gestion.cc
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Liste.h"
#include "Etudiant.h"
#include "gestion.h"

using namespace std;

   
// comme son nom l'indique...
void afficherListe( const Liste<Etudiant> & liste )
{
  TAdresse adr = liste.adressePremier();
  while( adr != liste.null() )
  {
    cout << liste.valeurElement( adr ) << endl;
    adr = liste.adresseSuivant( adr );
  } 
}
  

// crée une liste à partir d'un fichier
void fic2liste( const string & file, Liste<Etudiant> & l )
{
	fstream f;
	
	f.open( file.data(), ios::in ); 
	l.insererEnTete( Etudiant( f ) );
	TAdresse adr = l.adressePremier();
	while (f != NULL )
	{
		l.insererApres( Etudiant( f ), adr);
		adr = l.adresseSuivant(adr);
	}
	
	f.close();
}

// sauvegarde une liste dans un fichier
void liste2fic( const string & file, Liste<Etudiant> & l )
{
	fstream f;
	
	f.open( file.data(), ios::out ); 
	TAdresse adr = l.adressePremier();
	while (adr != l.null() )
	{
		l.valeurElement(adr).ecrireFlux(f);
		adr = l.adresseSuivant(adr);
	}
	
	f.close();
}

// et tout ce qui peut servir...
// à compléter

