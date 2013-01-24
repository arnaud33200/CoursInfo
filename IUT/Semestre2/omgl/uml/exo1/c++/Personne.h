/************************************************************************
                        Personne.h.h - Copyright aladouce

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
The original location of this file is /net/8280/Home/aladouce/omgl/uml/c++/Personne.h
**************************************************************************/


#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include vector

#include "Catégorie_Musicale.h"
#include "Album.h"

class Personne
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Personne ( );

  /**
   * Empty Destructor
   */
  virtual ~Personne ( );



  /**
   * Constructeur paramétré de la classe Personne ( 3 paramètres )
   * @param  nom
   * @param  dateNais
   * @param  prénom
   */
   Personne (string nom, string dateNais, string prénom );

protected:

public:

protected:

public:

protected:


private:

  // Private attributes
  //  

  int m_numPersonne;
  string m_nomPersonne;
  string m_prénomPersonne;
  string m_dateNaissance;

  // Dertermine la catégorie musical préférée de l'auditeur
  Catégorie_Musicale * m_préférée;

  // tu vois ta vu
  vector<Album*> m_propriétéVector;
public:

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of m_numPersonne
   * @param new_var the new value of m_numPersonne
   */
  void setNumPersonne ( int new_var );

  /**
   * Get the value of m_numPersonne
   * @return the value of m_numPersonne
   */
  int getNumPersonne ( );


  /**
   * Set the value of m_nomPersonne
   * @param new_var the new value of m_nomPersonne
   */
  void setNomPersonne ( string new_var );

  /**
   * Get the value of m_nomPersonne
   * @return the value of m_nomPersonne
   */
  string getNomPersonne ( );


  /**
   * Set the value of m_prénomPersonne
   * @param new_var the new value of m_prénomPersonne
   */
  void setPrénomPersonne ( string new_var );

  /**
   * Get the value of m_prénomPersonne
   * @return the value of m_prénomPersonne
   */
  string getPrénomPersonne ( );


  /**
   * Set the value of m_dateNaissance
   * @param new_var the new value of m_dateNaissance
   */
  void setDateNaissance ( string new_var );

  /**
   * Get the value of m_dateNaissance
   * @return the value of m_dateNaissance
   */
  string getDateNaissance ( );

private:


  /**
   * Set the value of m_préférée
   * Dertermine la catégorie musical préférée de l'auditeur
   * @param new_var the new value of m_préférée
   */
  void setPréférée ( Catégorie_Musicale * new_var );

  /**
   * Get the value of m_préférée
   * Dertermine la catégorie musical préférée de l'auditeur
   * @return the value of m_préférée
   */
  Catégorie_Musicale * getPréférée ( );


  /**
   * Add a Propriété object to the m_propriétéVector List
   * tu vois ta vu
   */
  void addPropriété ( Album * add_object );

  /**
   * Remove a Propriété object from m_propriétéVector List
   * tu vois ta vu
   */
  void removePropriété ( Album * remove_object );

  /**
   * Get the list of Propriété objects held by m_propriétéVector
   * tu vois ta vu
   * @return vector<Album *> list of Propriété objects held by m_propriétéVector
   */
  vector<Album *> getPropriétéList ( );

  void initAttributes ( ) ;

};

#endif // PERSONNE_H
