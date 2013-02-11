/* test_sequence.c */

#include "sequence.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void main (int argc, char* argv[]) 
{
  int pos = 0;
  int length = 0;
  sequence s = sequence_create();
  srand(time(NULL));
   
  while(length < 20) {
    char * c = malloc(sizeof(char));
    *c = getc(stdin);
    if(*c == '\n') continue;
    pos = (int) (length * (rand() / (RAND_MAX + 1.0)));
    printf("try to insert %s at pos %d...\n",c,pos);
    sequence_insert(s,c,pos);
    length++;
    sequence_dump(s);
  }

  sequence_destroy(s);
}
