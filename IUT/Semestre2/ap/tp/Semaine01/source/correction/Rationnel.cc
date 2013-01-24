#include <string>
#include "Rationnel.h"
#include "util.h"

using namespace std;

Rationnel::Rationnel()
{
  my_num=0;
  my_deno=1;
}

Rationnel::Rationnel(int a, int b)
{
  my_num=a;
  my_deno=b;
}


Rationnel::~Rationnel()
{
}

void
Rationnel::setNum(int a)
{
  my_num=a;
}

void
Rationnel::setDeno(int b)
{
  my_deno=b;
}


void
Rationnel::simplifie()
{
  int d=pgcd(abs(my_num), abs(my_deno));
  if(d!=0){
    my_num/=d;
    my_deno/=d;
  }
}

string
Rationnel::toString() const
{
  Rationnel q(my_num, my_deno);
  string my_num_s, slash_s, my_deno_s;

  q.simplifie();
  if(q.my_deno<0){
    q.my_num=-q.my_num; 
    q.my_deno=-q.my_deno;
  }
  my_num_s=intToString(q.my_num);
  if(q.my_deno==1||q.my_num==0)
    slash_s=my_deno_s="";
  else{
    slash_s="/";
    my_deno_s=intToString(q.my_deno);
  }

  return my_num_s+slash_s+my_deno_s;
}


void
Rationnel::soustraction(Rationnel autre, Rationnel& difference) const
{
  difference.my_deno=my_deno*autre.my_deno; 
  difference.my_num=my_num*autre.my_deno-autre.my_num*my_deno;
}

bool
Rationnel::equal(Rationnel autre) const 
{
  if(my_deno == autre.my_deno) return my_num == autre.my_num;
  
  int my_multiplied_num = my_num * autre.my_deno;
  int autre_multiplied_num = autre.my_num * my_deno;
  return my_multiplied_num == autre_multiplied_num;
}
