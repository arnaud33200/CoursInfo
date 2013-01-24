/************************************************************************
                        Véhicule_Automobile.h.h - Copyright aladouce

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
The original location of this file is /net/8280/Home/aladouce/omgl/uml/carloc/c++/Véhicule_Automobile.h
**************************************************************************/


#ifndef VÉHICULE_AUTOMOBILE_H
#define VÉHICULE_AUTOMOBILE_H

#include string
#include vector

class Agence;
class Agence;
#include "Emprunt.h"

class Véhicule_Automobile
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Véhicule_Automobile ( );

  /**
   * Empty Destructor
   */
  virtual ~Véhicule_Automobile ( );


protected:

public:

protected:

public:

protected:


private:


  Agence * m_être l'arrivé;

  Agence * m_être le depart;

  Emprunt * m_est concerné;
public:

private:

public:

private:


  /**
   * Set the value of m_être l'arrivé
   * @param new_var the new value of m_être l'arrivé
   */
  void setÊtre l'arrivé ( Agence * new_var );

  /**
   * Get the value of m_être l'arrivé
   * @return the value of m_être l'arrivé
   */
  Agence * getÊtre l'arrivé ( );


  /**
   * Set the value of m_être le depart
   * @param new_var the new value of m_être le depart
   */
  void setÊtre le depart ( Agence * new_var );

  /**
   * Get the value of m_être le depart
   * @return the value of m_être le depart
   */
  Agence * getÊtre le depart ( );


  /**
   * Set the value of m_est concerné
   * @param new_var the new value of m_est concerné
   */
  void setEst concerné ( Emprunt * new_var );

  /**
   * Get the value of m_est concerné
   * @return the value of m_est concerné
   */
  Emprunt * getEst concerné ( );



};

#endif // VÉHICULE_AUTOMOBILE_H
