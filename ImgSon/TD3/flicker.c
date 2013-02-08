#include <stdio.h>
#include <stdlib.h>
#include <math.h>



#define LARGEUR 256
#define HAUTEUR 256
#define VAL_MAX 255


#define min(a,b) (a<b)?a:b; 

// Definition du type representant une image en
// niveaux de gris (ndg)
typedef int ndgIm [LARGEUR][HAUTEUR];

// Histogramme
typedef int histo[256];



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
}






void
copie_ndgIm (ndgIm dst, ndgIm src)
{
  int x, y;
  for (x = 0; x < LARGEUR; x++)
    for (y = 0; y < HAUTEUR; y++)
      dst[x][y] = src[x][y];
}

// Histogrammes 
void remplir_histogramme(ndgIm im, histo h){ 
  int i, x, y; 
  for (i = 0; i < VAL_MAX; i++) 
    h[i] = 0; 
  for (y = 0; y < HAUTEUR; y++) 
    for (x = 0; x < LARGEUR; x++) 
      h[im[x][y]]++; 
} 

// Histogrammes cumules
void cumul_histogramme(histo h, histo H)
{ 
  for (int i = 0; i <= VAL_MAX; ++i)
  {
    H[i] = h[0];
    for (int j = 1; j <= j; ++j)
    {
      H[i] += h[j]; 
    }
  }
}

void restaure(ndgIm im, ndgIm dest, histo H, histo H0)
{
  
}    

int main (int argc, char** argv)
{
  char name[50];
  ndgIm im, dest;
  histo* h = malloc(20*sizeof(histo));
  histo* H = malloc(20*sizeof(histo));

  for (int t=0; t<20; t++) {
    sprintf(name,"OurShin/OurShin1946_00%02d.pgm",t);
    lireNdgImage(name, im);
    remplir_histogramme(im, h[t]);
    cumul_histogramme(im, h[t], H[t]);
  }

  for (int t=1; t<20; t++) {
    sprintf(name,"OurShin/OurShin1946_00%02d.pgm",t);
    lireNdgImage(name, im);

    restaure(im, dest, H[t], H[0]) ;
    sprintf(name,"OurShin/Res_00%02d.pgm",t);
    ecrireNdgImage (name,dest);
      
      
  }
  free(h);
  free(H);

  return EXIT_SUCCESS;
}
