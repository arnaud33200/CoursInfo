#include <stdio.h>
#include <stdlib.h>
#include <math.h>



#define LARGEUR 256
#define HAUTEUR 256
#define VAL_MAX 255


#define R 0
#define G 1
#define B 2



// Definition du type representant une image en
// niveaux de gris (ndg)
typedef int ndgIm [LARGEUR][HAUTEUR];
// Image couleur
typedef int coulIm [LARGEUR][HAUTEUR][3];



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
      {
        fprintf (descFic, "%d ", im[x][y]);
      }
      fprintf (descFic, "\n");
    }

  fclose (descFic);
  printf("Ecriture du fichier : %s\n", nom);
}

/* Question 3.1 */
void convolution(ndgIm src, ndgIm dest, int** filtre, int largeur_filtre, int hauteur_filtre, int norm)
{
  int x,y,ix,iy;

  for (y=0;y<HAUTEUR; y++)
  {  
    for (x=0;x<LARGEUR; x++)
    {
      if (y>=hauteur_filtre/2 && y<HAUTEUR-hauteur_filtre/2 
        && x>=largeur_filtre/2 && x<LARGEUR - largeur_filtre/2)
      {
        int somme = 0;
        for (iy=(-hauteur_filtre/2); iy<=hauteur_filtre/2; iy++)
        { 
        	for (ix=(-largeur_filtre/2); ix<=largeur_filtre/2; ix++)
          {
        	  somme += src[x+ix][y+iy] * filtre[ix+(largeur_filtre/2)][iy+(hauteur_filtre/2)];
          }
        }

        somme = somme / norm;
        dest[x][y] = somme;
        if ( dest[x][y] > 255) dest[x][y] = 255;  
        if ( dest[x][y] < 0) dest[x][y] = 0;  
      }
      else
        dest[x][y]=0;
    }
  }
}

void filtre_moyenne3(ndgIm src, ndgIm dest)
{
  int** filtre;
  int largeur_filtre = 3;
  int hauteur_filtre = 3;
  filtre =(int**) malloc((largeur_filtre)*sizeof(int*));  
  for (int ix=0; ix<largeur_filtre; ix++)
    filtre[ix] =(int*) malloc((hauteur_filtre)*sizeof(int));  
  for (int iy=0; iy<hauteur_filtre; iy++)
    for (int ix=0; ix<largeur_filtre; ix++)
      filtre[ix][iy] = 1;

  convolution(src, dest, filtre, 3, 3, 9);

  for (int ix=0;ix<largeur_filtre; ix++)
    free(filtre[ix]);
  free(filtre);
}

void filtre_gaussien3(ndgIm src, ndgIm dest)
{
  int** filtre;
  int largeur_filtre = 3;
  int hauteur_filtre = 3;
  filtre =(int**) malloc((largeur_filtre)*sizeof(int*));  
  for (int ix=0; ix<largeur_filtre; ix++)
    filtre[ix] =(int*) malloc((hauteur_filtre)*sizeof(int));  
  
  filtre[0][0] = 1; filtre[1][0] = 2; filtre[2][0] = 1; 
  filtre[0][1] = 2; filtre[1][1] = 4; filtre[2][1] = 2; 
  filtre[0][2] = 1; filtre[1][2] = 2; filtre[2][2] = 1; 

  convolution(src, dest, filtre, 3, 3, 16);

  for (int ix=0;ix<largeur_filtre; ix++)
    free(filtre[ix]);
  free(filtre);
}

void filtre_Sobel_Vert3(ndgIm src, ndgIm dest)
{
  int** filtre;
  int largeur_filtre = 3;
  int hauteur_filtre = 3;
  filtre =(int**) malloc((largeur_filtre)*sizeof(int*));  
  for (int ix=0; ix<largeur_filtre; ix++)
    filtre[ix] =(int*) malloc((hauteur_filtre)*sizeof(int));  
  
  filtre[0][0] = -1; filtre[1][0] = 0; filtre[2][0] = 1; 
  filtre[0][1] =-2; filtre[1][1] = 0; filtre[2][1] = 2; 
  filtre[0][2] = -1; filtre[1][2] = 0; filtre[2][2] = 1; 

  convolution(src, dest, filtre, 3, 3, 4);

  for (int ix=0;ix<largeur_filtre; ix++)
    free(filtre[ix]);
  free(filtre);
}

void filtre_Sobel_Hori3(ndgIm src, ndgIm dest)
{
  int** filtre;
  int largeur_filtre = 3;
  int hauteur_filtre = 3;
  filtre =(int**) malloc((largeur_filtre)*sizeof(int*));  
  for (int ix=0; ix<largeur_filtre; ix++)
    filtre[ix] =(int*) malloc((hauteur_filtre)*sizeof(int));  
  
  filtre[0][0] = -1; filtre[1][0] = -2; filtre[2][0] = -1; 
  filtre[0][1] = 0; filtre[1][1] = 0; filtre[2][1] = 0; 
  filtre[0][2] = 1; filtre[1][2] = 2; filtre[2][2] = 1; 

  convolution(src, dest, filtre, 3, 3, 4);

  for (int ix=0;ix<largeur_filtre; ix++)
    free(filtre[ix]);
  free(filtre);
}

void norm(ndgIm src1, ndgIm src2, ndgIm dest)
{
  int x,y;
  for (y=0;y<HAUTEUR; y++)
    for (x=0;x<LARGEUR; x++)
      dest[x][y] = sqrt( (src1[x][y]*src1[x][y]) + (src2[x][y]*src2[x][y]) );
}

int main ()
{
  ndgIm im1, im2, nim1, nim2, dest;
  
  lireNdgImage ("lena.pgm", im1);
  lireNdgImage ("lena.pgm", im2);

  filtre_Sobel_Vert3(im1, nim1);
  filtre_Sobel_Hori3(im2, nim2);

  norm(nim1, inm2, dest);

  ecrireNdgImage ("conv.pgm", dest);

  return EXIT_SUCCESS;
}
