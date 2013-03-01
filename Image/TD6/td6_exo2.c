#include <math.h>
#include <stdlib.h>
#include <stdio.h> 
/* fichiers d'entetes OpenGL, GLU et GLUT */
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


double y;
double z;
double x;

// frappes de touches normales
void 
keyboardFunc (unsigned char key, int x, int y)
{
  switch (key)
  {
    case 'd': y += 0.2; break;
    case 'f': y -= 0.2; break;
    case 'e': x += 0.1; break;
    case 'r': x -= 0.1; break;
    case 'c': z += 0.1; break;
    case 'v': z -= 0.1; break;
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
  gluLookAt (x, y, z, 0.,0, 0, 0.0, 10.0, 0.0);   /*Visualisation de la scène */

  glColor3f(0.,1.,0.);/* couleur courante */


  /* Question 2.4*/
  glRotatef (60,0,0,1);  
  glTranslatef (0.5,0,0); 

  glRectf(-0.3,-0.3,0.3,0.3) ; //Tracer un rectangle

  glutSwapBuffers ();
}

int main (int argc, char **argv)
{
  y = 1.0;
  x = 1.0;
  z = 1.0;

  glutInit (&argc, argv);
  glutInitWindowPosition (0, 0);
  glutInitWindowSize (640, 480);

  glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE |GLUT_DEPTH);

  if (glutCreateWindow ("TD6: Initiation a OpenGL") <= 0)
  {
    fprintf (stderr, "Impossible de creer la fenetre Glut.\n");
    exit(EXIT_FAILURE);
  }
  glClearColor (0.5, 0.5, 0.5, 1.0);

  glutDisplayFunc (displayFunc);/* fonction d'affichage */
  glutKeyboardFunc (keyboardFunc); /* gestion du clavier */

  glutMainLoop ();/* lancement de la boucle principale */

  return EXIT_SUCCESS;
}

