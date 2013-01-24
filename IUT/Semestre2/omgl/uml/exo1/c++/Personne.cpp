/************************************************************************
                        Personne.h.cpp - Copyright aladouce

Here you can write a license for your code, some comments or any other
information you want to have in your generated code. To to this simply
configure the "headings" directory in uml to point to a directory
where you have your heading files.

or you can just replace the contents of this file with your own.
If you want to do this, this file is located at

/usr/share/apps/umbrello/headings/heading.cpp

-->Code Generators searches for heading files based on the file extension
   i.e. it will look for a file name ending in ".h" to include in C++ header
   files, and for a file name ending in ".java" to include in all generated
   java code.
   If you name the file "heading.<extension>", Code Generator will always
   choose this file even if there are other files with the same extension in the
   directory. If you name the file something else, it must be the only one with that
   extension in the directory to guarantee that Code Generator will choose it.

you can use variables in your heading files which are replaced at generation
time. possible variables are : author, date, time, filename and filepath.
just write %variable_name%

This file was generated on mar mar 8 2011 at 09:23:03
The original location of this file is /net/8280/Home/aladouce/omgl/uml/c++/Personne.cpp
**************************************************************************/

#include "Personne.h"

// Constructors/Destructors
//  

Personne::Personne ( ) {
initAttributes();
}

Personne::~Personne ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Private attribute accessor methods
//  


/**
 * Set the value of m_numPersonne
 * @param new_var the new value of m_numPersonne
 */
void Personne::setNumPersonne ( int new_var ) {
  m_numPersonne = new_var;
}

/**
 * Get the value of m_numPersonne
 * @return the value of m_numPersonne
 */
int Personne::getNumPersonne ( ) {
  return m_numPersonne;
}

/**
 * Set the value of m_nomPersonne
 * @param new_var the new value of m_nomPersonne
 */
void Personne::setNomPersonne ( string new_var ) {
  m_nomPersonne = new_var;
}

/**
 * Get the value of m_nomPersonne
 * @return the value of m_nomPersonne
 */
string Personne::getNomPersonne ( ) {
  return m_nomPersonne;
}

/**
 * Set the value of m_prénomPersonne
 * @param new_var the new value of m_prénomPersonne
 */
void Personne::setPrénomPersonne ( string new_var ) {
  m_prénomPersonne = new_var;
}

/**
 * Get the value of m_prénomPersonne
 * @return the value of m_prénomPersonne
 */
string Personne::getPrénomPersonne ( ) {
  return m_prénomPersonne;
}

/**
 * Set the value of m_dateNaissance
 * @param new_var the new value of m_dateNaissance
 */
void Personne::setDateNaissance ( string new_var ) {
  m_dateNaissance = new_var;
}

/**
 * Get the value of m_dateNaissance
 * @return the value of m_dateNaissance
 */
string Personne::getDateNaissance ( ) {
  return m_dateNaissance;
}

/**
 * Set the value of m_préférée
 * Dertermine la catégorie musical préférée de l'auditeur
 * @param new_var the new value of m_préférée
 */
void Personne::setPréférée ( Catégorie_Musicale * new_var ) {
  m_préférée = new_var;
}

/**
 * Get the value of m_préférée
 * Dertermine la catégorie musical préférée de l'auditeur
 * @return the value of m_préférée
 */
Catégorie_Musicale * Personne::getPréférée ( ) {
  return m_préférée;
}

/**
 * Add a Propriété object to the m_propriétéVector List
 * tu vois ta vu
 */
void Personne::addPropriété ( Album * add_object ) {
  m_propriétéVector.push_back(add_object);
}

/**
 * Remove a Propriété object from m_propriétéVector List
 * tu vois ta vu
 */
void Personne::removePropriété ( Album * remove_object ) {
  int i, size = m_propriétéVector.size();
  for ( i = 0; i < size; i++) {
  	Album * item = m_propriétéVector.at(i);
  	if(item == remove_object) {
  		vector<Album *>::iterator it = m_propriétéVector.begin() + i;
  		m_propriétéVector.erase(it);
  		return;
  	}
   }
}

/**
 * Get the list of Propriété objects held by m_propriétéVector
 * tu vois ta vu
 * @return vector<Album *> list of Propriété objects held by m_propriétéVector
 */
vector<Album *> Personne::getPropriétéList ( ) {
  return m_propriétéVector;
}

// Other methods
//  


/**
 * Constructeur paramétré de la classe Personne ( 3 paramètres )
 * @param  nom
 * @param  dateNais
 * @param  prénom
 */
 Personne::Personne (string nom, string dateNais, string prénom ) {

}

void Personne::initAttributes ( ) {
  m_préférée = new Catégorie_Musicale( );
}

