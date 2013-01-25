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

// Definition du type representant une image en
// niveaux de gris (ndg)
typedef unsigned char ndgIm [LARGEUR][HAUTEUR];
// Image couleur
typedef unsigned char coulIm [LARGEUR][HAUTEUR][3];

typedef float histo[256];


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
void lireNdgImage (char *nom, ndgIm im)
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

// ~~~~ EXERCICE III ~~~~~~~

void imageUnie(char* nom, int ng)
{
	FILE * newimg = fopen(nom, "w+");
	ecrireEnTete(newimg, "P2");
	
	int x,y;
	for (y=0; y<HAUTEUR; y++)
	{
		for (x=0; x<LARGEUR; x++)
			fprintf(newimg, "%d ", ng);
		fprintf(newimg, "\n");
	}
	
	printf("Fichier %s créer !\n", nom);
	fclose(newimg);
}

void degradeHorizontal(char * nom, int ng1, int ng2)
{
	FILE * newimg = fopen(nom, "w+");
	ecrireEnTete(newimg, "P2");
	
	int x,y;
	for (y=0; y<HAUTEUR; y++)
	{
		for (x=0; x<LARGEUR; x++)
		{
			float m1 = (LARGEUR*1.0-(x+1))/LARGEUR;
			float m2 = (x+1)*1.0/LARGEUR;
			int c = (m1*ng1) + (m2*ng2);
			fprintf(newimg, "%d ", c);
		}
		//~ printf("\n");
	}
	printf("Fichier %s créer !\n", nom);
	fclose(newimg);
}

// ~~~~~ EXERCICE IV ~~~~~~~~~


// Lecture d'une image en ndg: mise a jour de la 
// structure de donnees de type ndgIm
void lireCoulImage (char *nom, coulIm im)
{
  FILE *descFic = NULL;
  int c, x, y, z;

  ouvrirFichier (nom, &descFic, "r");
  lireEnTete (descFic, "P3");

  for (y=0; y < HAUTEUR; y++)  
    for (x=0; x < LARGEUR; x++)
    {
		for (z=0; z<3; z++)
		{
			fscanf (descFic, "%d", &c);
			im[x][y][z] = c;
		}
    }
  
  fclose (descFic);
}

// Ecrit une image en ndg
void 
ecrireCoulImage (char *nom, coulIm im)
{
  FILE *descFic = NULL;
  int x, y, z;
  
  ouvrirFichier (nom, &descFic, "w+");
  ecrireEnTete (descFic, "P3");
  
  for (y=0; y < HAUTEUR; y++)
  {
	for (x=0; x < LARGEUR; x++)
		for (z=0; z<3; z++)
			fprintf (descFic, "%d ", im[x][y][z]);
	fprintf (descFic, "\n");
  }

  fclose (descFic);
}

// ~~~~~ EXERCICE V ~~~~~~~~~

void RGBToGray(coulIm src, ndgIm dest)
{
	int x, y, z;
	int rgb[3];
	
	for (y=0; y < HAUTEUR; y++)
		for (x=0; x < LARGEUR; x++)
		{
			for (z=0; z<3; z++)
				rgb[z] = src[x][y][z];
			dest[x][y] = 0.3*rgb[0] + 0.59*rgb[1] + 0.11*rgb[2];
		}
}

//~ /**********************/
//~ // Question 8.3
//~ /**********************/
//~ void histogramme_dat(char* hnom, histo h){ 
  //~ FILE *hfile = NULL;
  //~ ouvrirFichier (hnom, &hfile, "w");
  //~ int i; 
  //~ for (i = 0; i < VAL_MAX; i++) 
    //~ fprintf(hfile,"%d %f \n", i,h[i]); 
  //~ fclose(hfile);
//~ } 


int 
main ()
{
  coulIm im;
  ndgIm d;
  
  lireCoulImage ("fleur.ppm", im);
  
   //~ ajout du pixel noir
  //~ im[128][128][0] = 0;
  //~ im[128][128][1] = 255;
  //~ im[128][128][2] = 0;
  
  RGBToGray(im,d);

  
  ecrireNdgImage ("test.ppm", d);
  degradeHorizontal("degrade.pgm", 75, 203);

	imageUnie("gris.pgm", 50);


  return EXIT_SUCCESS;
}
