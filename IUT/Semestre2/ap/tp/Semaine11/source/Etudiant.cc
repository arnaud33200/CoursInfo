//////////////////////////////////////////////////////////////////////////////
/// Etudiant.cc   
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Etudiant.h"

using namespace std;


Etudiant::Etudiant()
{
  m_nom = "pas de nom";
  m_note = 0;
}

Etudiant::~Etudiant()
{
}

Etudiant::Etudiant(string nom, float note)
{
  m_nom = nom;
  m_note = note;
}

Etudiant::Etudiant(const Etudiant &etud)
{
  m_nom = etud.m_nom;
  m_note = etud.m_note;
}

Etudiant &Etudiant::operator= (const Etudiant &etud)
{
  if (this != &etud)
    {
      m_nom = etud.m_nom;
      m_note = etud.m_note;
    }

  return *this;
}

string Etudiant::nom() const
{
  return m_nom;
}

float Etudiant::note() const
{
  return m_note;
}

void Etudiant::saisie()
{
  cout << "nom de l'etudiant ?" << endl;
  cin >> m_nom;
  cout << "note de l'etudiant ?" << endl;
  cin >> m_note;
}


ostream & operator<<(ostream &os, const Etudiant &e)
{
  os << "nom:" << e.nom() << " - note:" << e.note() << endl;
  return os;
}

