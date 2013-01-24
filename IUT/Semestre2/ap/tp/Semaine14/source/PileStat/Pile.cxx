#include <assert.h>

template < class T >
Pile<T>::Pile(){
  m_sommet = -1;
}

template < class T >
Pile<T>::Pile(const Pile &p){
  m_sommet = p.m_sommet;
  for(int i = 0; i < m_sommet; i++)
    m_corps[i] = p.m_corps[i];
}

template < class T >
Pile<T>::~Pile(){
}

template < class T >
void Pile<T>::empiler(const T& elem){
  assert(!pilePleine());
  m_sommet++;
  m_corps[m_sommet] = elem;
}

template < class T >
void Pile<T>::depiler(){
  assert(!pileVide());
  m_sommet--;
}

template < class T >
T Pile<T>::valeurSommet() const {
  assert(!pileVide());
  return m_corps[m_sommet];
}

template < class T >
bool Pile<T>::pileVide() const {
  return (m_sommet == -1);
}

template < class T >
bool Pile<T>::pilePleine() const {
  return (m_sommet != TAILLE_PILE - 1);
}
