///////////////////////////////////////////////////////////////////////////////
// Liste.cxx
//
// Author: JOL 2000/10/20
// Version : MM 2002/02/20 modifs mineures
// Version : ID 2002/03/19 prototype insererApres comme en ASD
// Version : MM 2004/03/05 suppression de afficher()
// Version : ID 2008/03/28 modification class<==> typename + include .cxx dans .h
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// ------------------------- Standard services -----------------------------
template<typename TInfo>
Liste<TInfo>::Liste()
  : m_list()
{
#ifdef TRACE_LISTE
  cout << "[Liste()] Liste vide creee." 
       << endl;
#endif // #ifdef TRACE_LISTE
}

template<typename TInfo>
Liste<TInfo>::~Liste()
{
  // le destructeur de 'm_list' est automatiquement appele.
#ifdef TRACE_LISTE
  cout << "[~Liste()] Liste detruite." 
       << endl;
#endif // #ifdef TRACE_LISTE
}

template<typename TInfo>
Liste<TInfo>::Liste( const Liste & other )
  : m_list( other.m_list )
{
#ifdef TRACE_LISTE
  cout << "[Liste(const Liste &)] Liste copiee." 
       << endl;
#endif // #ifdef TRACE_LISTE
}

template<typename TInfo>
Liste<TInfo> & 
Liste<TInfo>::operator=( const Liste & other )
{
#ifdef TRACE_LISTE
  cout << "[Liste<TInfo> & operator=(const Liste &)] Liste affectee." 
  << endl;
#endif // #ifdef TRACE_LISTE
  m_list = other.m_list;
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
// ------------------------- List services ---------------------------------
template<typename TInfo>
typename Liste<TInfo>::TIterator
Liste<TInfo>::adressePremier() const
{
#ifdef TRACE_LISTE
  cout << "[adressePremier()] Adresse du premier element retournee." 
       << endl;
#endif // #ifdef TRACE_LISTE
  return m_list.begin();
}


template<typename TInfo>
typename Liste<TInfo>::TIterator
Liste<TInfo>::adresseSuivant( TIterator adr ) const
{
  if ( adr == null() )
    erreur( "[Liste<TInfo>::AdresseSuivant] "
	    "suivant de NULL non defini." );
#ifdef TRACE_LISTE
  cout << "[adresseSuivant( TIterator adr )] Adresse suivante retournee." 
       << endl;
#endif // #ifdef TRACE_LISTE
  return ++adr;
}

template<typename TInfo>
TInfo
Liste<TInfo>::valeurElement( TIterator adr ) const
{
  if ( adr == null() )
    erreur( "[Liste<TInfo>::valeurElement] "
	    "valeur de NULL non defini." );
#ifdef TRACE_LISTE
  cout << "[valeurElement()] Valeur de l'element pointe : " << *adr 
       << endl;
#endif // #ifdef TRACE_LISTE
  return *adr;
}

template<typename TInfo>
void
Liste<TInfo>::modifieValeur( TIterator adr, const TInfo & valeur )
{
  if ( adr == null() )
    erreur( "[Liste<TInfo>::modifieValeur] "
	    "impossible de modifier la valeur de NULL." );
#ifdef TRACE_LISTE
  cout << "[modifieValeur()] Nouvelle valeur de l'element pointe : " << valeur 
       << endl;
#endif // #ifdef TRACE_LISTE
  *adr = valeur;
}

template<typename TInfo>
void
Liste<TInfo>::insererEnTete( const TInfo & valeur )
{
#ifdef TRACE_LISTE
  cout << "[insererEnTete(...)] Insertion en tete de la valeur : " << valeur 
       << endl;
#endif // #ifdef TRACE_LISTE
  m_list.push_front( valeur );
}

template<typename TInfo>
void
Liste<TInfo>::insererApres( const TInfo & valeur, TIterator adr )
{
  if ( adr == null() )
    erreur( "[Liste<TInfo>::insererApres] "
	    "impossible d'inserer apres NULL." );
#ifdef TRACE_LISTE
  cout << "[insererApres(...)] Insertion apres de la valeur : " << valeur 
       << endl;
#endif // #ifdef TRACE_LISTE
  m_list.insert( ++adr, valeur );
}

template<typename TInfo>
void
Liste<TInfo>::supprimerEnTete()
{
  if ( adressePremier() == null() )
    erreur( "[Liste<TInfo>::supprimerEnTete] "
	    "impossible de supprimer un element de la liste vide." );
#ifdef TRACE_LISTE
  cout << "[supprimerEnTete()] Suppression du premier element." 
       << endl;
#endif // #ifdef TRACE_LISTE
  m_list.pop_front();
}

template<typename TInfo>
void
Liste<TInfo>::supprimerApres( TIterator adr )
{
  if ( adr == null() )
    erreur( "[Liste<TInfo>::supprimerEnTete] "
	    "impossible de supprimer apres NULL." );
#ifdef TRACE_LISTE
  cout << "[supprimerApres()] Suppression apres l'adresse donnee." 
       << endl;
#endif // #ifdef TRACE_LISTE
  m_list.erase( ++adr );
}

template<typename TInfo>
typename Liste<TInfo>::TIterator 
Liste<TInfo>::null() const
{
  return m_list.end();
}

///////////////////////////////////////////////////////////////////////////////
// ------------------------- services pour debuguer ----------------------


template<typename TInfo>
void
Liste<TInfo>::erreur( const string & msg ) const
{
  cerr << "ERREUR : " << msg 
       << endl;
  exit( -1 );
}

