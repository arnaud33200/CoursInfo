/************************************************************************
                        Client.h.h - Copyright aladouce

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
The original location of this file is /net/8280/Home/aladouce/omgl/uml/carloc/c++/Client.h
**************************************************************************/


#ifndef CLIENT_H
#define CLIENT_H

#include string
#include vector

class Réservation;

class Client
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Client ( );

  /**
   * Empty Destructor
   */
  virtual ~Client ( );


protected:

public:

protected:

public:

protected:


private:

  // Private attributes
  //  

  int m_numClient;
  string m_prénomClient;
  string m_nomClient;
  string m_adresseClient;

  vector<Réservation*> m_avoirVector;
public:

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of m_numClient
   * @param new_var the new value of m_numClient
   */
  void setNumClient ( int new_var );

  /**
   * Get the value of m_numClient
   * @return the value of m_numClient
   */
  int getNumClient ( );


  /**
   * Set the value of m_prénomClient
   * @param new_var the new value of m_prénomClient
   */
  void setPrénomClient ( string new_var );

  /**
   * Get the value of m_prénomClient
   * @return the value of m_prénomClient
   */
  string getPrénomClient ( );


  /**
   * Set the value of m_nomClient
   * @param new_var the new value of m_nomClient
   */
  void setNomClient ( string new_var );

  /**
   * Get the value of m_nomClient
   * @return the value of m_nomClient
   */
  string getNomClient ( );


  /**
   * Set the value of m_adresseClient
   * @param new_var the new value of m_adresseClient
   */
  void setAdresseClient ( string new_var );

  /**
   * Get the value of m_adresseClient
   * @return the value of m_adresseClient
   */
  string getAdresseClient ( );

private:


  /**
   * Add a Avoir object to the m_avoirVector List
   */
  void addAvoir ( Réservation * add_object );

  /**
   * Remove a Avoir object from m_avoirVector List
   */
  void removeAvoir ( Réservation * remove_object );

  /**
   * Get the list of Avoir objects held by m_avoirVector
   * @return vector<Réservation *> list of Avoir objects held by m_avoirVector
   */
  vector<Réservation *> getAvoirList ( );

  void initAttributes ( ) ;

};

#endif // CLIENT_H
