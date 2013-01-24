/************************************************************************
                        Réservation.h.cpp - Copyright aladouce

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

This file was generated on mar mar 8 2011 at 10:02:29
The original location of this file is /net/8280/Home/aladouce/omgl/uml/carloc/c++/Réservation.cpp
**************************************************************************/

#include "Réservation.h"

// Constructors/Destructors
//  

Réservation::Réservation ( ) {
initAttributes();
}

Réservation::~Réservation ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Private attribute accessor methods
//  


/**
 * Set the value of m_numRéservation
 * @param new_var the new value of m_numRéservation
 */
void Réservation::setNumRéservation ( int new_var ) {
  m_numRéservation = new_var;
}

/**
 * Get the value of m_numRéservation
 * @return the value of m_numRéservation
 */
int Réservation::getNumRéservation ( ) {
  return m_numRéservation;
}

/**
 * Set the value of m_dateRéservation
 * @param new_var the new value of m_dateRéservation
 */
void Réservation::setDateRéservation ( string new_var ) {
  m_dateRéservation = new_var;
}

/**
 * Get the value of m_dateRéservation
 * @return the value of m_dateRéservation
 */
string Réservation::getDateRéservation ( ) {
  return m_dateRéservation;
}

/**
 * Set the value of m_dateDepart
 * @param new_var the new value of m_dateDepart
 */
void Réservation::setDateDepart ( string new_var ) {
  m_dateDepart = new_var;
}

/**
 * Get the value of m_dateDepart
 * @return the value of m_dateDepart
 */
string Réservation::getDateDepart ( ) {
  return m_dateDepart;
}

/**
 * Set the value of m_dateRetour
 * @param new_var the new value of m_dateRetour
 */
void Réservation::setDateRetour ( string new_var ) {
  m_dateRetour = new_var;
}

/**
 * Get the value of m_dateRetour
 * @return the value of m_dateRetour
 */
string Réservation::getDateRetour ( ) {
  return m_dateRetour;
}

/**
 * Set the value of m_choisi
 * @param new_var the new value of m_choisi
 */
void Réservation::setChoisi ( Modèle * new_var ) {
  m_choisi = new_var;
}

/**
 * Get the value of m_choisi
 * @return the value of m_choisi
 */
Modèle * Réservation::getChoisi ( ) {
  return m_choisi;
}

/**
 * Set the value of m_pris
 * @param new_var the new value of m_pris
 */
void Réservation::setPris ( Client * new_var ) {
  m_pris = new_var;
}

/**
 * Get the value of m_pris
 * @return the value of m_pris
 */
Client * Réservation::getPris ( ) {
  return m_pris;
}

void Réservation::initAttributes ( ) {
  m_choisi = new Modèle( );
  m_pris = new Client( );
}

