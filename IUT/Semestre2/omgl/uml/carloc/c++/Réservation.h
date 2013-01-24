/************************************************************************
                        Réservation.h.h - Copyright aladouce

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

This file was generated on mar mar 8 2011 at 10:02:29
The original location of this file is /net/8280/Home/aladouce/omgl/uml/carloc/c++/Réservation.h
**************************************************************************/


#ifndef RÉSERVATION_H
#define RÉSERVATION_H

#include string
#include vector

#include "Modèle.h"
#include "Client.h"

class Réservation
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Réservation ( );

  /**
   * Empty Destructor
   */
  virtual ~Réservation ( );


protected:

public:

protected:

public:

protected:


private:

  // Private attributes
  //  

  int m_numRéservation;
  string m_dateRéservation;
  string m_dateDepart;
  string m_dateRetour;

  Modèle * m_choisi;

  Client * m_pris;
public:

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of m_numRéservation
   * @param new_var the new value of m_numRéservation
   */
  void setNumRéservation ( int new_var );

  /**
   * Get the value of m_numRéservation
   * @return the value of m_numRéservation
   */
  int getNumRéservation ( );


  /**
   * Set the value of m_dateRéservation
   * @param new_var the new value of m_dateRéservation
   */
  void setDateRéservation ( string new_var );

  /**
   * Get the value of m_dateRéservation
   * @return the value of m_dateRéservation
   */
  string getDateRéservation ( );


  /**
   * Set the value of m_dateDepart
   * @param new_var the new value of m_dateDepart
   */
  void setDateDepart ( string new_var );

  /**
   * Get the value of m_dateDepart
   * @return the value of m_dateDepart
   */
  string getDateDepart ( );


  /**
   * Set the value of m_dateRetour
   * @param new_var the new value of m_dateRetour
   */
  void setDateRetour ( string new_var );

  /**
   * Get the value of m_dateRetour
   * @return the value of m_dateRetour
   */
  string getDateRetour ( );

private:


  /**
   * Set the value of m_choisi
   * @param new_var the new value of m_choisi
   */
  void setChoisi ( Modèle * new_var );

  /**
   * Get the value of m_choisi
   * @return the value of m_choisi
   */
  Modèle * getChoisi ( );


  /**
   * Set the value of m_pris
   * @param new_var the new value of m_pris
   */
  void setPris ( Client * new_var );

  /**
   * Get the value of m_pris
   * @return the value of m_pris
   */
  Client * getPris ( );


  void initAttributes ( ) ;

};

#endif // RÉSERVATION_H
