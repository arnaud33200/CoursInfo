/************************************************************************
                        Artiste.h.cpp - Copyright aladouce

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
The original location of this file is /net/8280/Home/aladouce/omgl/uml/c++/Artiste.cpp
**************************************************************************/

#include "Artiste.h"

// Constructors/Destructors
//  

Artiste::Artiste ( ) {
initAttributes();
}

Artiste::~Artiste ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Private attribute accessor methods
//  


/**
 * Set the value of m_maisonDisque
 * @param new_var the new value of m_maisonDisque
 */
void Artiste::setMaisonDisque ( string new_var ) {
  m_maisonDisque = new_var;
}

/**
 * Get the value of m_maisonDisque
 * @return the value of m_maisonDisque
 */
string Artiste::getMaisonDisque ( ) {
  return m_maisonDisque;
}

/**
 * Add a Oeuvres object to the m_oeuvresVector List
 * l'album est créer par un ou des artistes
 */
void Artiste::addOeuvres ( Album * add_object ) {
  m_oeuvresVector.push_back(add_object);
}

/**
 * Remove a Oeuvres object from m_oeuvresVector List
 * l'album est créer par un ou des artistes
 */
void Artiste::removeOeuvres ( Album * remove_object ) {
  int i, size = m_oeuvresVector.size();
  for ( i = 0; i < size; i++) {
  	Album * item = m_oeuvresVector.at(i);
  	if(item == remove_object) {
  		vector<Album *>::iterator it = m_oeuvresVector.begin() + i;
  		m_oeuvresVector.erase(it);
  		return;
  	}
   }
}

/**
 * Get the list of Oeuvres objects held by m_oeuvresVector
 * l'album est créer par un ou des artistes
 * @return vector<Album *> list of Oeuvres objects held by m_oeuvresVector
 */
vector<Album *> Artiste::getOeuvresList ( ) {
  return m_oeuvresVector;
}

void Artiste::initAttributes ( ) {
}

