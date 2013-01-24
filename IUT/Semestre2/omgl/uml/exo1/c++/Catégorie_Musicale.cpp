/************************************************************************
                        Catégorie_Musicale.h.cpp - Copyright aladouce

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
The original location of this file is /net/8280/Home/aladouce/omgl/uml/c++/Catégorie_Musicale.cpp
**************************************************************************/

#include "Catégorie_Musicale.h"

// Constructors/Destructors
//  

Catégorie_Musicale::Catégorie_Musicale ( ) {
initAttributes();
}

Catégorie_Musicale::~Catégorie_Musicale ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Private attribute accessor methods
//  


/**
 * Set the value of m_numCatégorie
 * @param new_var the new value of m_numCatégorie
 */
void Catégorie_Musicale::setNumCatégorie ( int new_var ) {
  m_numCatégorie = new_var;
}

/**
 * Get the value of m_numCatégorie
 * @return the value of m_numCatégorie
 */
int Catégorie_Musicale::getNumCatégorie ( ) {
  return m_numCatégorie;
}

/**
 * Set the value of m_IntituléCatégorie
 * @param new_var the new value of m_IntituléCatégorie
 */
void Catégorie_Musicale::setIntituléCatégorie ( string new_var ) {
  m_IntituléCatégorie = new_var;
}

/**
 * Get the value of m_IntituléCatégorie
 * @return the value of m_IntituléCatégorie
 */
string Catégorie_Musicale::getIntituléCatégorie ( ) {
  return m_IntituléCatégorie;
}

// Other methods
//  


/**
 * @param  libellé
 */
 Catégorie_Musicale::Catégorie_Musicale (string libellé ) {

}

void Catégorie_Musicale::initAttributes ( ) {
}

