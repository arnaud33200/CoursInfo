///////////////////////////////////////////////////////////////////////////////
// Pile.cc
// Version : ID 2008/03/28 modification class<==> typename + include .cxx dans .h
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

//- Constante de classe donnant la taille maximale possible pour la pile.
template<typename TInfo>
const int Pile<TInfo>::TAILLE_PILE = 100;

//- Constructeur par defaut.
template<typename TInfo>
Pile<TInfo>::Pile()
{
#ifdef TRACE_PILE
  cout << "[Pile<TInfo>::Pile()] cree une pile vide." << endl;
#endif // #ifdef TRACE_PILE
  m_sp = new TInfo[ TAILLE_PILE ];
  m_sommet = -1;
}

//- Constructeur de copie.
//- @param other la pile a recopier.
template<typename TInfo>
Pile<TInfo>::Pile( const Pile<TInfo> & pile)
{
#ifdef TRACE_PILE
  cout << "[Pile<TInfo>::Pile( const Pile<TInfo> & pile)]"
       << " copie " << pile.m_sommet+1 << " element(s)."
       << endl;
#endif // #ifdef TRACE_PILE
  int i;
  m_sp = new TInfo[ TAILLE_PILE ];
  m_sommet = pile.m_sommet;
  for ( i = 0; i <= m_sommet; i++ )
    m_sp[ i ] = pile.m_sp[ i ];
}

//- Destructeur.
template<typename TInfo>
Pile<TInfo>::~Pile()
{
#ifdef TRACE_PILE
  cout << "[Pile<TInfo>::~Pile()] detruit la pile." << endl;
#endif // #ifdef TRACE_PILE
  delete[] m_sp;
}

//- @return 'true' si la pile etait vide, 'false' sinon.
template<typename TInfo>
bool Pile<TInfo>::pileVide() const
{
#ifdef TRACE_PILE
  cout << "[Pile<TInfo>::pileVide()]";
  if ( m_sommet == -1 ) cout << " la pile est vide.";
  else cout << " la pile n'est pas vide.";
  cout << endl;
#endif // #ifdef TRACE_PILE
  return m_sommet == -1;
}

// @return la valeur situee sur le sommet de la pile.
template<typename TInfo>
TInfo Pile<TInfo>::valeurSommet() const
{
#ifdef TRACE_PILE
  cout << "[Pile<TInfo>::valeurSommet()]" 
       << " la valeur du sommet est " << m_sp[ m_sommet ] << "."
       << endl;
#endif // #ifdef TRACE_PILE
  return m_sp[ m_sommet ];
}

//- Empile la valeur [val] donnee en parametre.
//- @param val une valeur.
template<typename TInfo>
void Pile<TInfo>::empiler( const TInfo & val )
{
#ifdef TRACE_PILE
  cout << "[Pile<TInfo>::empiler()]"
       << " empile la valeur " << val << "."
       << endl;
#endif // #ifdef TRACE_PILE
  m_sp[ ++m_sommet ] = val;
}

//- Depile.
template<typename TInfo>
void Pile<TInfo>::depiler()
{
#ifdef TRACE_PILE
  cout << "[Pile<TInfo>::depiler()] depile." << endl;
#endif // #ifdef TRACE_PILE
  m_sommet--;
}




