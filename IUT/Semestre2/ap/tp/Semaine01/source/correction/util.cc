#include <sstream> 
#include <string> 
#include "util.h"

using namespace std;

int
pgcd(int a, int b)
{
  if(b==0)
    return a;
  else
    return pgcd(b, a%b);
}

string
intToString(int x)
{
  ostringstream oss;
  oss << x;
  string x_s = oss.str();
  return x_s;
}


