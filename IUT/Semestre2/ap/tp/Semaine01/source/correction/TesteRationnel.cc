#include <iostream>
#include "Rationnel.h"

using namespace std;

int
main()
{
  Rationnel q1, q2(24,-16);

  cout << q1.toString() << " " << q2.toString() << " "
       << Rationnel(231,232).toString()
       << " " << Rationnel(231,-231).toString() << endl<< endl;

  Rationnel t[5];
  for(int i = 0; i<5; i++){
    t[i].setNum(i);
    t[i].setDeno(i+1);
    cout << t[i].toString() << endl;
  }

  cout << endl;

  Rationnel q3(5,6), q4(6,12);
  cout << q3.toString() << " == " << q4.toString() << " : " << (q3.equal(q4)? "true":"false") << endl;

  q3.soustraction(q4, q1);
  cout << q3.toString() << " - " << q4.toString() << " = " << q1.toString()
       << endl;

  return 0;
}
