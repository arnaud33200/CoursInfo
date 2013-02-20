/* test_sequence.c */

#include "sequence.h"
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

void main (int argc, char* argv[]) 
{
  srand(time(NULL));
  char * c = malloc(sizeof(char));
  *c = 'A';
   
  struct timeval start, end; 
  double time_exp, time_amorti;
  int n, max = 1000000;
  
  printf("# n time_exp(µs) time_amorti(µs)\n");        
  
  for(n = 10 ; n < max ; n *= 2)
  {
    // create stack
    sequence s = sequence_create();
    
    gettimeofday(&start,NULL);
    
    // push n times in the stack
    int pos = 0;
    int length = 0;
    while(length < n)
    {
      pos = (int) (length * (rand() / (RAND_MAX + 1.0)));
      // for (int i = 0; i < n/5; ++i)
      // {
        sequence_insert(s,c,pos);
        length++;
        pos++;

      // }
    }
    
    gettimeofday(&end,NULL);
    
    time_exp = ((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec)); // µs
    time_amorti = time_exp / n;
    
    printf("%d %.2f %.2f\n",n,time_exp,time_amorti);
    
    sequence_destroy(s);
  }
}
