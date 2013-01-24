/************************************************************************
                        Album.h.h - Copyright aladouce

Here you can write a license for your code, some comments or any other
information you want to have in your generated code. To to this simply
configure the "headings" directory in uml to point to a directory
where you have your heading files.

or you can just replace the contents of this file with your own.
If you want to do this, this file is located at

/usr/share/apps/umbrello/headings/heading.h

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
The original location of this file is /net/8280/Home/aladouce/omgl/uml/c++/Album.h
**************************************************************************/


#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include vector

#include "Catégorie_Musicale.h"
class Artiste;

class Album
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Album ( );

  /**
   * Empty Destructor
   */
  virtual ~Album ( );



  /**
   * @param  nom
   * @param  nbPistes
   */
   Album (string nom, int nbPistes );

protected:

public:

protected:

public:

protected:


private:

  // Private attributes
  //  

  int m_numAlbum;
  string m_nomAlbum;
  int m_nbPistes;

  // determine la catégorie musical d'un album
  vector<Catégorie_Musicale*> m_catégorie albumVector;

  // l'artiste crées des albums
  vector<Artiste*> m_concepteurVector;
public:

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of m_numAlbum
   * @param new_var the new value of m_numAlbum
   */
  void setNumAlbum ( int new_var );

  /**
   * Get the value of m_numAlbum
   * @return the value of m_numAlbum
   */
  int getNumAlbum ( );


  /**
   * Set the value of m_nomAlbum
   * @param new_var the new value of m_nomAlbum
   */
  void setNomAlbum ( string new_var );

  /**
   * Get the value of m_nomAlbum
   * @return the value of m_nomAlbum
   */
  string getNomAlbum ( );


  /**
   * Set the value of m_nbPistes
   * @param new_var the new value of m_nbPistes
   */
  void setNbPistes ( int new_var );

  /**
   * Get the value of m_nbPistes
   * @return the value of m_nbPistes
   */
  int getNbPistes ( );

private:


  /**
   * Add a Catégorie album object to the m_catégorie albumVector List
   * determine la catégorie musical d'un album
   */
  void addCatégorie album ( Catégorie_Musicale * add_object );

  /**
   * Remove a Catégorie album object from m_catégorie albumVector List
   * determine la catégorie musical d'un album
   */
  void removeCatégorie album ( Catégorie_Musicale * remove_object );

  /**
   * Get the list of Catégorie album objects held by m_catégorie albumVector
   * determine la catégorie musical d'un album
   * @return vector<Catégorie_Musicale *> list of Catégorie album objects held by
   * m_catégorie albumVector
   */
  vector<Catégorie_Musicale *> getCatégorie albumList ( );

  /**
   * Add a Concepteur object to the m_concepteurVector List
   * l'artiste crées des albums
   */
  void addConcepteur ( Artiste * add_object );

  /**
   * Remove a Concepteur object from m_concepteurVector List
   * l'artiste crées des albums
   */
  void removeConcepteur ( Artiste * remove_object );

  /**
   * Get the list of Concepteur objects held by m_concepteurVector
   * l'artiste crées des albums
   * @return vector<Artiste *> list of Concepteur objects held by m_concepteurVector
   */
  vector<Artiste *> getConcepteurList ( );

  void initAttributes ( ) ;

};

#endif // ALBUM_H
