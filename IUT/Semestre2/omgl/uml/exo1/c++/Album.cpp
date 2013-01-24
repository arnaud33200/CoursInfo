/************************************************************************
                        Album.h.cpp - Copyright aladouce

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
The original location of this file is /net/8280/Home/aladouce/omgl/uml/c++/Album.cpp
**************************************************************************/

#include "Album.h"

// Constructors/Destructors
//  

Album::Album ( ) {
initAttributes();
}

Album::~Album ( ) { }

//  
// Methods
//  


// Accessor methods
//  


// Private attribute accessor methods
//  


/**
 * Set the value of m_numAlbum
 * @param new_var the new value of m_numAlbum
 */
void Album::setNumAlbum ( int new_var ) {
  m_numAlbum = new_var;
}

/**
 * Get the value of m_numAlbum
 * @return the value of m_numAlbum
 */
int Album::getNumAlbum ( ) {
  return m_numAlbum;
}

/**
 * Set the value of m_nomAlbum
 * @param new_var the new value of m_nomAlbum
 */
void Album::setNomAlbum ( string new_var ) {
  m_nomAlbum = new_var;
}

/**
 * Get the value of m_nomAlbum
 * @return the value of m_nomAlbum
 */
string Album::getNomAlbum ( ) {
  return m_nomAlbum;
}

/**
 * Set the value of m_nbPistes
 * @param new_var the new value of m_nbPistes
 */
void Album::setNbPistes ( int new_var ) {
  m_nbPistes = new_var;
}

/**
 * Get the value of m_nbPistes
 * @return the value of m_nbPistes
 */
int Album::getNbPistes ( ) {
  return m_nbPistes;
}

/**
 * Add a Catégorie album object to the m_catégorie albumVector List
 * determine la catégorie musical d'un album
 */
void Album::addCatégorie album ( Catégorie_Musicale * add_object ) {
  m_catégorie albumVector.push_back(add_object);
}

/**
 * Remove a Catégorie album object from m_catégorie albumVector List
 * determine la catégorie musical d'un album
 */
void Album::removeCatégorie album ( Catégorie_Musicale * remove_object ) {
  int i, size = m_catégorie albumVector.size();
  for ( i = 0; i < size; i++) {
  	Catégorie_Musicale * item = m_catégorie albumVector.at(i);
  	if(item == remove_object) {
  		vector<Catégorie_Musicale *>::iterator it = m_catégorie albumVector.begin() + i;
  		m_catégorie albumVector.erase(it);
  		return;
  	}
   }
}

/**
 * Get the list of Catégorie album objects held by m_catégorie albumVector
 * determine la catégorie musical d'un album
 * @return vector<Catégorie_Musicale *> list of Catégorie album objects held by
 * m_catégorie albumVector
 */
vector<Catégorie_Musicale *> Album::getCatégorie albumList ( ) {
  return m_catégorie albumVector;
}

/**
 * Add a Concepteur object to the m_concepteurVector List
 * l'artiste crées des albums
 */
void Album::addConcepteur ( Artiste * add_object ) {
  m_concepteurVector.push_back(add_object);
}

/**
 * Remove a Concepteur object from m_concepteurVector List
 * l'artiste crées des albums
 */
void Album::removeConcepteur ( Artiste * remove_object ) {
  int i, size = m_concepteurVector.size();
  for ( i = 0; i < size; i++) {
  	Artiste * item = m_concepteurVector.at(i);
  	if(item == remove_object) {
  		vector<Artiste *>::iterator it = m_concepteurVector.begin() + i;
  		m_concepteurVector.erase(it);
  		return;
  	}
   }
}

/**
 * Get the list of Concepteur objects held by m_concepteurVector
 * l'artiste crées des albums
 * @return vector<Artiste *> list of Concepteur objects held by m_concepteurVector
 */
vector<Artiste *> Album::getConcepteurList ( ) {
  return m_concepteurVector;
}

// Other methods
//  


/**
 * @param  nom
 * @param  nbPistes
 */
 Album::Album (string nom, int nbPistes ) {

}

void Album::initAttributes ( ) {
}

