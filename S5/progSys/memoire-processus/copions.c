#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char *my_strcpy(char *dest, const char *source)
{
  while ((*dest++ = *source++))
    ;
  return dest;
}


void afficher_proc_maps()
{
  char s[40] ;
  sprintf(s,"cat /proc/%d/maps", getpid());
  printf("Voici la carte de la mémoire :\n");
  printf("*****************\n");
  system(s);
  printf("*****************\n");
}

int
main ()
{
  afficher_proc_maps();
  char *pointeur_de_chaine = "  pointeur de chaine ";
  char tableau_de_caracteres[] = "tableau_de_caracteres";

  my_strcpy (tableau_de_caracteres, "dans le tableau");
  my_strcpy (pointeur_de_chaine, tableau_de_caracteres);

  return EXIT_SUCCESS;
}
