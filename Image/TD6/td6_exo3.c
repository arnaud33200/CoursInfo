#include <math.h>
#include <stdlib.h>
#include <stdio.h> 
/* fichiers d'entetes OpenGL, GLU et GLUT */
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

float a = 0;
float v = 0.1;
float n = 3.0;

void drawPlane (float s)
{
  float height=0;
  
  glColor3f(0.,1.,0.);/* couleur courante */
  // glBegin (GL_TRIANGLES);
  glBegin (GL_QUADS);
  glNormal3f (0.0, 0.0, n);

  glVertex3f (-s/2.0, -s/2.0,s/2.0);
  glVertex3f (s/2.0, -s/2.0, s/2.0);
  glVertex3f (s/2.0, s/2.0, s/2.0);
  glVertex3f (-s/2.0, s/2.0, s/2.0);

  glColor3f(1.,1.,0.);
  glVertex3f (-s/2.0, -s/2.0,-s/2.0);
  glVertex3f (s/2.0, -s/2.0, -s/2.0);
  glVertex3f (s/2.0, s/2.0, -s/2.0);
  glVertex3f (-s/2.0, s/2.0, -s/2.0);

  glColor3f(1.,0.,1.);
  glVertex3f (-s/2.0, s/2.0,-s/2.0);
  glVertex3f (s/2.0, s/2.0, -s/2.0);
  glVertex3f (s/2.0, s/2.0, s/2.0);
  glVertex3f (-s/2.0, s/2.0, s/2.0);
  glEnd ();
}

void drawRepere()
{
  
  glBegin (GL_LINES);
  glNormal3f (0.0, 0.0, 1.0);

  glColor3f(1.,0.,0.);/* couleur courante */
  glVertex3f (0, 0,0);
  glVertex3f (2.0, 0, 0);

  glColor3f(0.,0.,1.);/* couleur courante */
  glVertex3f (0, 0,0);
  glVertex3f (0, 2.0, 0);
  glEnd ();
}


// frappes de touches normales
void keyboardFunc (unsigned char key, int x, int y)
{
  switch (key)
  {
    case 'u': v += 0.1; break;
    case 'j': v -= 0.1; break;
    case 'i': n += 0.3; break;
    case 'k': n -= 0.3; break;
    case 'q':
    case 'Q':
    case 27:                       // Esc
      exit (EXIT_SUCCESS);
      break;

  }
  glutPostRedisplay ();
}



void displayFunc (void)
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  /* Transformation de projection */
  glMatrixMode (GL_PROJECTION);/* projection 3D-->2D */
  glLoadIdentity ();/*initialise la matrice a l'identite*/
  
  /* specification de la projection*/
  glFrustum(-2.0,2.0,-2.0,2.0,1.0,10.0);  /*Projection perspective*/


  /* Transformation de point de vue */
  glMatrixMode (GL_MODELVIEW);/* pile courante = matrice de point de vue  */
  glLoadIdentity (); /*initialise la matrice a l'identite*/ 
  gluLookAt (0.0, 0.0, 3.0, 0.,0, 0, 0.0, 1.0, 0.0);   /*Visualisation de la scène */

  glRotatef(a,1,1,0);
  glColor3f(0.,1.,0.);/* couleur courante */

  drawPlane(2.0);
  drawRepere();
  a+=v;	
  
  glutSwapBuffers ();
}


int main (int argc, char **argv)
{

  glutInit (&argc, argv);
  glutInitWindowPosition (0, 0);
  glutInitWindowSize (640, 480);

  glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );

  if (glutCreateWindow ("TD6: Initiation a OpenGL") <= 0)
    {
      fprintf (stderr, "Impossible de creer la fenetre Glut.\n");
      exit(EXIT_FAILURE);
    }
   glClearColor (0.5, 0.5, 0.5, 1.0);


   glEnable(GL_DEPTH_TEST);
  glutDisplayFunc (displayFunc);/* fonction d'affichage */
  glutIdleFunc(displayFunc);
  glutKeyboardFunc (keyboardFunc); /* gestion du clavier */
  

  glutMainLoop ();/* lancement de la boucle principale */

  return EXIT_SUCCESS;
}

