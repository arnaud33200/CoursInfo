// Liste.h
#ifndef _LISTEH_
#define _LISTEH_

template <class T>
struct Cellule
{
  T info; 
  int suivant;
};

template <class T>
class Liste 
{  
	private: 
  		static const int TAILLE_BLOC_BASE;
  		int m_tailleBloc;
  		Cellule<T> * m_bloc;
 	 	TAdresse m_premier, m_premierLibre;
  		void dupliquer( const Liste<T> & liste );
  		void agrandir();
	
	public:
  		typedef int TAdresse;
  		static const TAdresse NUL = -1;
  		Liste();
  		~Liste();
  		Liste( const Liste<T> & liste );
  		Liste<T> & operator=( const Liste<T> & liste );

  		TAdresse adressePremier() const;
  		TAdresse adresseSuivant( TAdresse adr ) const;
  
  		T valeurElement( TAdresse adr ) const;
  		void modifierValeur(const T& elem, TAdresse adr );
  		void insererEnTete( const T& elem );
  		void insererApres( const T& elem, TAdresse adr );
  		void supprimerEnTete();
  		void supprimerApres( TAdresse adr );

 //Méthodes à rajouter
 		void afficher() const;
  		//void placer(const T& elem);	
  		//void trier();
};

#include "Liste.cxx"

#endif
