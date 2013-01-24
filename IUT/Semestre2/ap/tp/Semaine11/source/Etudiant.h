///////////////////////////////////////////////////////////////////////////////
// Etudiant.h
///////////////////////////////////////////////////////////////////////////////

#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <iostream>
#include <string>

using namespace std;

class Etudiant
{
 private:
  float m_note;
  string m_nom;

 public:
  Etudiant();
  ~Etudiant();
  Etudiant(string nom, float note);
  Etudiant(const Etudiant &etud);
  Etudiant &operator= (const Etudiant &etud);
  
  string nom() const;
  float note() const;


  void saisie();
};

ostream & operator<<(ostream &os, const Etudiant &e);

#endif

