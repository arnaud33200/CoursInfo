#ifndef _RATIONNEL_H_
#define _RATIONNEL_H_

#include <string>

//using namespace std;

class Rationnel{
private:
  int my_num, my_deno;
public:
  Rationnel();
  Rationnel(int a, int b);
  ~Rationnel();

  void setNum(int a);
  void setDeno(int b);

  std::string toString() const;
  void simplifie();
  void soustraction(Rationnel autre, Rationnel & difference) const;

  bool equal(Rationnel autre) const;
};

#endif
