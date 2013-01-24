// Liste.h
#ifndef _LISTE_H
#define _LISTE_H

template <class T>
struct Cellule
{
  T info;
  Cellule * suivant;
};


template <class T>
class Liste 
{
	public:
  		typedef Cellule<T>* TAdresse;
  
  		Liste();
  		~Liste();

 	 	TAdresse adressePremier() const;
  		TAdresse adresseSuivant( TAdresse adr ) const;

  		T valeurElement( TAdresse adr ) const;
  		void modifierValeur( const T& elem, TAdresse adr );
  		void insererEnTete( const T& elem );
  		void insererApres( const T& elem, TAdresse adr );
  		void supprimerEnTete();
  		void supprimerApres( TAdresse adr );

 // à écrire plus tard
  		//Liste( const Liste<T> & liste );
  		//Liste<T> & operator=( const Liste<T> & liste );
  
// Méthodes à rajouter
  		void afficher() const;
  		void placer(const T& elem);
  		bool estTrie() const;
  		//void trier();
  		
  	private:
  		TAdresse m_premier;

};

#include "Liste.cxx"

#endif
