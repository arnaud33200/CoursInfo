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
   
  // while(length < 20000)
  // {
  //   char * c = malloc(sizeof(char));
  //   *c = getc(stdin);
  //   if(*c == '\n') continue;
  //   pos = (int) (length * (rand() / (RAND_MAX + 1.0)));
  //   // system("clear");
  //   // printf("try to insert \033[01;35m%s\033[00m at pos \033[01;35m%d\033[00m...\n",c,pos);
  //   sequence_insert(s,c,pos);
  //   length++;
  //   // sequence_dump(s);
  // }

  // while(length > 0)
  // {
  //   pos = (int) (length * (rand() / (RAND_MAX + 1.0)));
  //   // printf("try to delete at pos \033[01;35m%d\033[00m...\n",pos);
  //   sequence_delete(s,pos);
  //   length--;
  //   // sequence_dump(s);
  // }

  /******************************************/

  char * c = malloc(sizeof(char));
  *c = 'A';
  while(length < 20)
  {
    pos = (int) (length * (rand() / (RAND_MAX + 1.0)));
    printf("## ");
    // for (int i = 0; i < 20; ++i)
    // {
      printf("try to insert \033[01;35mA\033[00m at pos \033[01;35m%d\033[00m...\n",pos);
      sequence_insert(s,c,pos);
      length++;
      pos++;
      sequence_dump(s);
    // }
  }
  while(length > 0)
  {
    pos = (int) (length * (rand() / (RAND_MAX + 1.0)));
    printf("  ## ");
    for (int i = 0; i < 5; ++i)
    {
      printf("try to delete at pos \033[01;35m%d\033[00m...\n",pos);
      sequence_delete(s,pos);
      length--;
      pos--;
      sequence_dump(s);
    }
  }

  sequence_destroy(s);
}
