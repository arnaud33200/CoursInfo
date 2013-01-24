/************************************************************************
                        Agence.h.cpp - Copyright aladouce

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
The original location of this file is /net/8280/Home/aladouce/omgl/uml/carloc/c++/Agence.cpp
**************************************************************************/

#include "Agence.h"

// Constructors/Destructors
//  

Agence::Agence ( ) {
}

Agence::~Agence ( ) { }

//  
// Methods
//  


// Accessor methods
//  


/**
 * Add a Arrivé object to the m_arrivéVector List
 */
void Agence::addArrivé ( Véhicule_Automobile * add_object ) {
  m_arrivéVector.push_back(add_object);
}

/**
 * Remove a Arrivé object from m_arrivéVector List
 */
void Agence::removeArrivé ( Véhicule_Automobile * remove_object ) {
  int i, size = m_arrivéVector.size();
  for ( i = 0; i < size; i++) {
  	Véhicule_Automobile * item = m_arrivéVector.at(i);
  	if(item == remove_object) {
  		vector<Véhicule_Automobile *>::iterator it = m_arrivéVector.begin() + i;
  		m_arrivéVector.erase(it);
  		return;
  	}
   }
}

/**
 * Get the list of Arrivé objects held by m_arrivéVector
 * @return vector<Véhicule_Automobile *> list of Arrivé objects held by
 * m_arrivéVector
 */
vector<Véhicule_Automobile *> Agence::getArrivéList ( ) {
  return m_arrivéVector;
}

/**
 * Add a Partir object to the m_partirVector List
 */
void Agence::addPartir ( Véhicule_Automobile * add_object ) {
  m_partirVector.push_back(add_object);
}

/**
 * Remove a Partir object from m_partirVector List
 */
void Agence::removePartir ( Véhicule_Automobile * remove_object ) {
  int i, size = m_partirVector.size();
  for ( i = 0; i < size; i++) {
  	Véhicule_Automobile * item = m_partirVector.at(i);
  	if(item == remove_object) {
  		vector<Véhicule_Automobile *>::iterator it = m_partirVector.begin() + i;
  		m_partirVector.erase(it);
  		return;
  	}
   }
}

/**
 * Get the list of Partir objects held by m_partirVector
 * @return vector<Véhicule_Automobile *> list of Partir objects held by
 * m_partirVector
 */
vector<Véhicule_Automobile *> Agence::getPartirList ( ) {
  return m_partirVector;
}


