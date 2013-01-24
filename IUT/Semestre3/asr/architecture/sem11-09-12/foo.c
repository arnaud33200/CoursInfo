int foo(int a, int b)
{
  // return (a-b+9999999)*2*a;
  int i;
  for ( i=0; i<5; i++)
  {
	  a++;
  }
  return a+b;
}

int main()
{
  foo(20,5);
  
  return 0;
}
