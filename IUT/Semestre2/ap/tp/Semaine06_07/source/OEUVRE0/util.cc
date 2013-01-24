#include "util.h"
#include <cmath>
#include <cassert>

using namespace std;

string intToString(int x){
  string x_s;
  int a;

  if(x==0)
    x_s="0";
  else{
     x_s="";
    if(x<0)
      a=-x;
    else
      a=x;
    while(a>0){
      x_s= ((char)('0'+a%10))+x_s;
      a/=10;
    }
    if(x<0)
      x_s="-"+x_s;
  }
  return x_s;
}

string floatToString(float x, int precision){
  string x_s;

  if(x==0){
    x_s="0";
    for(int i=0;i<precision;i++)
      x_s+="0";
  }
  else{
    int partie_conservee = (int)(x * pow(10.0,(double)precision));
    x_s = intToString(partie_conservee);
  }
  if(precision > 0)
    x_s.insert(x_s.length() - precision, ".");
  
  return x_s;
}
