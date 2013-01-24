/************************************************************************
                        Véhicule_Automobile.h.cpp - Copyright aladouce

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
The original location of this file is /net/8280/Home/aladouce/omgl/uml/carloc/c++/Véhicule_Automobile.cpp
**************************************************************************/

#include "Véhicule_Automobile.h"

// Constructors/Destructors
//  

Véhicule_Automobile::Véhicule_Automobile ( ) {
}

Véhicule_Automobile::~Véhicule_Automobile ( ) { }

//  
// Methods
//  


// Accessor methods
//  


/**
 * Set the value of m_être l'arrivé
 * @param new_var the new value of m_être l'arrivé
 */
void Véhicule_Automobile::setÊtre l'arrivé ( Agence * new_var ) {
  m_être l'arrivé = new_var;
}

/**
 * Get the value of m_être l'arrivé
 * @return the value of m_être l'arrivé
 */
Agence * Véhicule_Automobile::getÊtre l'arrivé ( ) {
  return m_être l'arrivé;
}

/**
 * Set the value of m_être le depart
 * @param new_var the new value of m_être le depart
 */
void Véhicule_Automobile::setÊtre le depart ( Agence * new_var ) {
  m_être le depart = new_var;
}

/**
 * Get the value of m_être le depart
 * @return the value of m_être le depart
 */
Agence * Véhicule_Automobile::getÊtre le depart ( ) {
  return m_être le depart;
}

/**
 * Set the value of m_est concerné
 * @param new_var the new value of m_est concerné
 */
void Véhicule_Automobile::setEst concerné ( Emprunt * new_var ) {
  m_est concerné = new_var;
}

/**
 * Get the value of m_est concerné
 * @return the value of m_est concerné
 */
Emprunt * Véhicule_Automobile::getEst concerné ( ) {
  return m_est concerné;
}


