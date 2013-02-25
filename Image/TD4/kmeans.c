#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


#define LARGEUR 256
#define HAUTEUR 256
#define VAL_MAX 255

#define LARGEUR_REGION 64
#define HAUTEUR_REGION 32

#define R 0
#define G 1
#define B 2

int turn;

// Definition du type representant une image en
// niveaux de gris (ndg)
typedef int ndgIm [LARGEUR][HAUTEUR];
// Image couleur
typedef int coulIm [LARGEUR][HAUTEUR][3];

// generation de nombres aleatoires
int my_rand (void)
{
   static int first = 0;
   
   if (first == 0)
   {
      srand(time(NULL));
      first = 1;
   }
   return (rand ());
}

// mode = "r" ou "w"
void 
ouvrirFichier (char *nom, FILE **desc, char *mode)
{
  *desc = fopen (nom, mode);
  if (*desc == NULL)
    {
      fprintf (stderr, 
	       "\"%s\": nom de fichier incorrect", 
	       nom);
      if (mode [0] == 'w')
	fprintf (stderr, " ou ouverture en ecriture impossible.");
      exit (EXIT_FAILURE);
    }
}

// Lecture et verification que l'en-tete est correcte et correspond 
// bien a notre mode (P2 = ndg ASCII, P3 = rgb ASCII)
void
lireEnTete (FILE *descFic, char *mode)
{
  char c;
  int v;

  fscanf (descFic, "%c", &c);
  // Lecture du mode
  if (c != mode[0])
    {
      fprintf (stderr, "Mode non defini (%c*).\n", c);
      exit (EXIT_FAILURE);
    }
  fscanf (descFic, "%c", &c);
  if (c != mode[1])
    {
      fprintf (stderr, "%s est necessaire pour une image ASCII en niveaux de gris.\n", mode);
      exit (EXIT_FAILURE);
    }
  // Lecture des dimensions
  fscanf (descFic, "%d", &v);
  if (v != HAUTEUR)
    {
      fprintf (stderr, "La hauteur doit etre de %d.\n", HAUTEUR);
      exit (EXIT_FAILURE);
    }
  fscanf (descFic, "%d", &v);
  if (v != LARGEUR)
    {
      fprintf (stderr, "La largeur doit etre de %d.\n", LARGEUR);
      exit (EXIT_FAILURE);
    }
  // Et lecture de la valeur maximale d'une intensite
  fscanf (descFic, "%d", &v);
  if (v != VAL_MAX)
    {
      fprintf (stderr, "L'intensite maximale doit etre de %d.\n", VAL_MAX);
      exit (EXIT_FAILURE);
    }
}

// Lecture d'une image en ndg: mise a jour de la 
// structure de donnees de type ndgIm
void 
lireNdgImage (char *nom, ndgIm im)
{
  FILE *descFic = NULL;
  int c, x, y;

  ouvrirFichier (nom, &descFic, "r");
  lireEnTete (descFic, "P2");

  for (y=0; y < HAUTEUR; y++)  
    for (x=0; x < LARGEUR; x++)
      {
	fscanf (descFic, "%d", &c);
	im [x][y] = c;
      }
  
  fclose (descFic);
}

// Ecrit l'en-tete correcte en fonction du mode
// le fichier est deja ouvert
void 
ecrireEnTete (FILE *descFic, char *mode)
{
  fprintf (descFic, "%s\n", mode);
  fprintf (descFic, "%d %d\n", HAUTEUR, LARGEUR);
  fprintf (descFic, "%d\n", VAL_MAX);
}


// Ecrit une image en ndg
void 
ecrireNdgImage (char *nom, ndgIm im)
{
  FILE *descFic = NULL;
  int x, y;
  
  ouvrirFichier (nom, &descFic, "w");
  ecrireEnTete (descFic, "P2");
  
  for (y=0; y < HAUTEUR; y++)
    {
      for (x=0; x < LARGEUR; x++)
	fprintf (descFic, "%d ", im[x][y]);
      fprintf (descFic, "\n");
    }

  fclose (descFic);
  printf("ecriture du fichier : %s\n", nom );
}

void ecrireNdgImageTurn(char *nom, ndgIm im)
{
  char c[100];
  sprintf(c, "%s%d.pgm", nom, turn);
  ecrireNdgImage(c, im);
  turn++;
}

// ********************
// K-Means Clustering.
// ********************


int distance (int c1, int c2)
{ 
  int d = (c1-c2)*(c1-c2);    // (c1-c2)²
  return  d;
}


void kmeans (ndgIm src, ndgIm dest)
{
  int x, y, i;
  int hasChanged = 1;
  int c0 = 0, c1 = 255, mean0 = 0, mean1 = 0, n0 = 0, n1 = 0;
  while (hasChanged == 1)
  {
    // puts("UN TOUR DE BOUCHE");
    for (y = 0; y < HAUTEUR; y++)
      for (x = 0; x < LARGEUR; x++)
      {
        // printf("\t-(%d,%d) : mean0:%d - mean1:%d - n0:%d - n1:%d\n", x, y, mean0, mean1, n0, n1);
        int c = src[x][y];
        if(distance (c, c0) <= distance (c, c1))
        {
          mean0 += c;
          n0++;
          dest[x][y] = c0;
        }
        else
        {
          mean1 += c;
          n1++;
          dest[x][y] = c1;
        }
      }
      hasChanged = 0;

      if (n0 != 0) mean0 /= n0;
      if (n1 != 0) mean1 /= n1;

      if (mean0 != c0 || mean1 != c1)
      {
        hasChanged = 1;
        c0 = mean0;
        c1 = mean1;
      }

      mean0 = mean1 = n0 = n1 = 0;
      ecrireNdgImageTurn("res-boats", dest);
  }
}

void kmeansK (ndgIm src, ndgIm dest, int k)
{
  int x, y, i;
  int hasChanged = 1;

  int ck[k];
   // int ck[6] = {0, 50, 100, 150, 200, 255};
  int mean[k];
  int n[k];

  for (i = 0; i < k; ++i)
  {
    ck[i] = my_rand() / 10000000;
    if (ck[i] > 255) ck[i] = 255;
    if (ck[i] < 0) ck[i] = 0;
    printf("%d - ", ck[i] );

    mean[i] = 0;
    n[i] = 0;
  }
  printf("\n");

  while (hasChanged == 1)
  {
    for (y = 0; y < HAUTEUR; y++)
    {
      for (x = 0; x < LARGEUR; x++)
      {
        int c = src[x][y];
        int mini = 0;
        int mindist = distance (c, ck[0]);

        for (i = 0; i < k; ++i)
        {
          if (distance (c, ck[i]) <= mindist)
          {
            mindist = distance (c, ck[i]);
            mini = i;
          }
        }
        mean[mini] += c;
        n[mini]++;
        dest[x][y] = ck[mini];
      }
    }

    hasChanged = 0;

    for (i = 0; i < k; ++i)
    {
      if (n[i]!=0) mean[i] /= n[i];
      if (mean[i] != ck[i]) hasChanged = 1;
    }

    for (i = 0; i < k; ++i)
    {
      if( hasChanged == 1 )
        ck[i] = mean[i];
      mean[i] = 0;
      n[i] = 0;
    }
    // ecrireNdgImageTurn("res-boats", dest);
  }
}

void kmeansPos (ndgIm src, ndgIm dest, int k)
{
  int x, y, i;
  int hasChanged = 1;

  int lxy[k][3];
   // int ck[6] = {0, 50, 100, 150, 200, 255};
  int mean[k];
  int n[k];

  for (i = 0; i < k; ++i)
  {
    ck[i] = my_rand() / 10000000;
    if (ck[i] > 255) ck[i] = 255;
    if (ck[i] < 0) ck[i] = 0;
    printf("%d - ", ck[i] );

    mean[i] = 0;
    n[i] = 0;
  }
  printf("\n");

  while (hasChanged == 1)
  {
    for (y = 0; y < HAUTEUR; y++)
    {
      for (x = 0; x < LARGEUR; x++)
      {
      	int c = src[x][y];
        int mini = 0;
        int mindist = distance (c, ck[0]);

        for (i = 0; i < k; ++i)
        {
          if (distance (c, ck[i]) <= mindist)
          {
            mindist = distance (c, ck[i]);
            mini = i;
          }
        }
        mean[mini] += c;
        n[mini]++;
        dest[x][y] = ck[mini];
      }
    }

    hasChanged = 0;

    for (i = 0; i < k; ++i)
    {
      if (n[i]!=0) mean[i] /= n[i];
      if (mean[i] != ck[i]) hasChanged = 1;
    }

    for (i = 0; i < k; ++i)
    {
      if( hasChanged == 1 )
        ck[i] = mean[i];
      mean[i] = 0;
      n[i] = 0;
    }
    // ecrireNdgImageTurn("res-boats", dest);
  }
}


// *******************

int main ()
{
  turn = 0;
  ndgIm im, res;
  lireNdgImage ("camera.pgm", im);
  kmeansK(im, res, 4);
  ecrireNdgImageTurn("res-boats", res);

  return EXIT_SUCCESS;
}
