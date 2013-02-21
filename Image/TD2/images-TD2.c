#include <stdio.h>
#include <stdlib.h>
#include <math.h>



#define LARGEUR 256
#define HAUTEUR 256
#define VAL_MAX 255


#define R 0
#define G 1
#define B 2

#define PI 3.14159265358979323846

#define get_min(a,b) (a<b)?a:b; 
#define get_max(a,b) (a>b)?a:b; 

// Definition du type representant une image en
// niveaux de gris (ndg)
typedef unsigned char ndgIm [LARGEUR][HAUTEUR];
// Image couleur
typedef unsigned char coulIm [LARGEUR][HAUTEUR][3];


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



void lireCoulImage (char *nom, coulIm im)
{
  FILE *descFic = NULL;

  int canalRouge, canalVert, canalBleu, x, y;

  ouvrirFichier (nom, &descFic, "r");
  lireEnTete (descFic, "P3");

  for (y=0; y < HAUTEUR; y++)  
    for (x=0; x < LARGEUR; x++)
      {
	fscanf (descFic, "%d", &canalRouge);
	im [x][y][0] = canalRouge;
	fscanf (descFic, "%d", &canalVert);
	im [x][y][1] = canalVert;
	fscanf (descFic, "%d", &canalBleu);
	im [x][y][2] = canalBleu;
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
  printf("Ecriture du fichier : %s\n", nom);
}


void 
ecrireCoulImage (char *nom, coulIm im)
{
  FILE *descFic = NULL;
  int x, y;

  ouvrirFichier (nom, &descFic, "w");
  ecrireEnTete (descFic, "P3");
  
  for (y=0; y < HAUTEUR; y++)
    {
      for (x=0; x < LARGEUR; x++)
	{
	  fprintf (descFic, "%d ", im[x][y][0]);
	  fprintf (descFic, "%d ", im[x][y][1]);
	  fprintf (descFic, "%d ", im[x][y][2]);
	}
      fprintf (descFic, "\n");
    }
  fclose (descFic);
}

void extremum(ndgIm im, int & min, int & max)
{
  max = 0;
  min = 255;
  for (int i = 0; i < 256; ++i)
    for (int j = 0; j < 256; ++j)
    {
      if (im[i][j] > max)
        max = im[i][j];
      if (im[i][j] < min)
        min = im[i][j];
    }
}

void augmenterConstraste(ndgIm im)
{
  int min, max;
  extremum(im, min, max);
  // float coef = 255/((max-min)*2.0);
  for (int i = 0; i < 256; ++i)
    for (int j = 0; j < 256; ++j)
    {
        im[i][j] = (im[i][j]-min)/(max-min)*255;
    }
}

void binarisation(ndgIm im, ndgIm dest, int seuil)
{
  for (int i = 0; i < 256; ++i)
    for (int j = 0; j < 256; ++j)
    {
      if(im[j][i] >=seuil)
        im[j][i] = 255;
      else
        im[j][i] = 0;
    }
}

void inversionHorizontal(ndgIm im, ndgIm dest)
{
  for (int i = 0; i < 256; ++i)
    for (int j = 0; j < 256; ++j)
    {
      dest[i][j] = im[255-i][j];
    } 
}

void rotation (ndgIm im, ndgIm dest, float angle)
{
  float r = angle *PI/180;
  int xc=127, yc=127;

  for (int y = 0; y < 256; ++y)
    for (int x = 0; x < 256; ++x)
    {
      int nx = ((x-xc)*cos(r)-(y-yc)*sin(r)) + xc;
      int ny = ((y-yc)*cos(r)+(x-xc)*sin(r)) + yc;
      if( nx>=0 && ny>=0 && nx <= 255 && ny <= 255)
        dest[x][y] = im[nx][ny];
   }

}

void diffImage( ndgIm imA, ndgIm imB, ndgIm imC )
{
  for (int y = 0; y < 256; ++y)
    for (int x = 0; x < 256; ++x)
    {
      imC[x][y] = imA[x][y] - imB[x][y];
      if (imC[x][y] < 0)
      {
        imC[x][y] = 0;
      }
   }
}

void addImageColor( coulIm imA, coulIm imB, coulIm imC )
{
  for (int y = 0; y < 256; ++y)
    for (int x = 0; x < 256; ++x)
      for (int c = 0; c < 3; ++c)
      {
        imC[x][y][c] = imA[x][y][c] + imB[x][y][c];
        if (imC[x][y][c] > 255)
        {
          imC[x][y][c] = 255;
        }
   }
}

void superpose( coulIm imA, coulIm imB, coulIm imC, float p )
{
  if ( p >= 1 || p <= 0 )
  {
    printf("ERREUR superpose : pourcentage melange entre 0 et 1\n");
    exit(1);
  }

  for (int y = 0; y < 256; ++y)
    for (int x = 0; x < 256; ++x)
      for (int c = 0; c < 3; ++c)
      {
        imC[x][y][c] = (imA[x][y][c]*p) + (imB[x][y][c]*(1-p));
        if (imC[x][y][c] > 255)
          imC[x][y][c] = 255;
        if (imC[x][y][c] < 0)
          imC[x][y][c] = 0;
   }
}

int main ()
{
  coulIm ima, imb, dest;
  
//   lireNdgImage ("baboon.pgm", im);

// // CONTRASTE
//   int min, max;
//   extremum(im,min,max);
//   printf("GRIS MAX = %i ET MIN = %i\n", max, min);
//   augmenterConstraste(im);
//   extremum(im,min,max);
//   printf("GRIS MAX = %i ET MIN = %i\n", max, min);
//   ecrireNdgImage ("test.pgm", im);

// BINARISATION
  // binarisation(im, dest, 127);
  // lireNdgImage ("brume.pgm", im);

  // inversionHorizontal(im, dest);

  // ecrireNdgImage ("test.pgm", dest);


  //   lireNdgImage ("diffA.pgm", ima);
  //   lireNdgImage ("diffB.pgm", imb);
  //   diffImage(ima, imb, dest);
  // ecrireNdgImage ("difftest.pgm", dest);

  lireCoulImage("fond.ppm", ima);
  lireCoulImage("guigui.ppm", imb);
  superpose(ima, imb, dest, 0.3);
  ecrireCoulImage("addtest.ppm", dest);

  // Question 5.1 
  // ndgIm im1,im2;
  // lireNdgImage("diffA.pgm", im1);
  // lireNdgImage("diffB.pgm", im2);

  // ecrireNdgImage ("diff.pgm",dest);

  // Question 5.2 et 5.3 
  // coulIm im3,im4,destC;
  // lireCoulImage("fond.ppm", im3);
  // lireCoulImage("objet.ppm", im4);

  // ecrireCoulImage ("add.ppm",destC);
  // ecrireCoulImage ("supp.ppm",destC);

  return EXIT_SUCCESS;
}
