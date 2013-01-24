// fichier Date.h

#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

class Date {
public:
  Date();
  Date( int j, int m, int a );
  Date( const Date & d );
  ~Date();
  void setDate( int j, int m, int a );
  void getDate( int &j, int &m, int &a ) const;
  string toString() const;
private:
  int my_jour;
  int my_mois;
  int my_annee;
};

#endif // #ifndef DATE_H

