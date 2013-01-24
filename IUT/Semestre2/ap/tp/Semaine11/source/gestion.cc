#include <iostream>

#include "gestion.h"

using namespace std;

///###################### LISTE NON TRIEE ############################

void saisirListe( Liste<Etudiant>* l )
{
	Etudiant* etu;
	int n, note;
	string nom;
	do
	{
		cout << "quelle est la taille de la liste d'Etudiant ?" << endl;
		cin >> n;
		if ( n < 0 ) cout << "		Entrez une valeur positif !" << endl;
	}
	while ( n < 0 );
	
	for ( int i =0; i<n; i++)
	{
		cout << "nom de l'étudiant n°" << i+1 << " = " << endl;
		cin >> nom;
		cout << "note de l'étudiant n°" << i+1 << " = " << endl;
		cin >> note;
		etu = new Etudiant(nom,note);
		l->insererEnTete(*etu);
		delete etu;
	}
}

void afficherListe( const Liste<Etudiant>* & l )
{
	Etudiant* etu;
	int i=1;
	TAdresse adr = l->adressePremier();
	while (adr != l->null() )
	{
		etu = new Etudiant( l->valeurElement(adr) );
		cout << "etudiant n°" << i << " :" << endl
			 << "	  nom = " << etu->nom() << " note = " << etu->note() << endl;
		delete etu;
		i++;
		adr = l->adresseSuivant(adr);
	}
}

int rangEtudiant( const string & n, const Liste<Etudiant>* & l )
{
	Etudiant* etu;
	int i = 1;
	bool present = false;
	TAdresse adr = l->adressePremier();
	
	while (adr != l->null() && not present )
	{
		etu = new Etudiant( l->valeurElement(adr) );
		if ( n == etu->nom() )
		{
			present = true;
			delete etu;
		}
		delete etu;
		i++;
		adr = l->adresseSuivant(adr);
	}
	if ( present ) return i;
	else return 0;
}

float moyenNote( const Liste<Etudiant>* & l )
{
	Etudiant* etu;
	int i=1;
	float somme=0;
	TAdresse adr = l->adressePremier();
	while (adr != l->null() )
	{
		etu = new Etudiant( l->valeurElement(adr) );
		somme += etu->note();
		delete etu;
		i++;
		adr = l->adresseSuivant(adr);
	}
	return somme/i;
}


/// ######################### LISTE TRIEE ############################


void ajouterEtudiant( Liste<Etudiant>* l, const Etudiant & etu )
{
	TAdresse adr = l->adressePremier(), adr2;
	bool bon = false;
	while (adr2 != l->null() && not bon )
	{
		if ( etu.nom() > l->valeurElement(adr))
		{
			bon = true;
			l->insererApres(etu, adr)
		}
		else if ( etu.nom() == l->valeurElement(adr) )
		{
			adr2 = l->adresseSuivant(adr);
			if ( etu.nom() < l->valeurElement(adr2) )
			{
				bon = true;
				l->insererApres(etu, adr)
			}
		}
		else adr = l->adresseSuivant(adr);
	}
}
