 #include <GL/glut.h> // fichiers d ’ entete OpegnGL
 
void clavier( unsigned char touche, int x, int y);
void affichage();
void mouse( int button , int state , int x , int y );
void mousemotion( int x , int y );
void reshape ( int x , int y );

typedef struct
{
	float x, y, z;
	float r, g, b;
} point;

point p;
int f[6][4];
float anglex = 50.0F;
float angley = 10.0F;
float anglez = 0.0F;
int zoom=1;
int presse;
int xold, yold;
 
int main(int argc, char **argv)
{
	glutInit( &argc , argv );
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glEnable( GL_DEPTH_TEST );

	glutInitWindowPosition(200,200);
	glutInitWindowSize( 250, 250);
	glutCreateWindow( "ogl1" );
	
  	glutDisplayFunc(affichage);
  	glutKeyboardFunc(clavier);
	glutMouseFunc(mouse);
	glutMotionFunc(mousemotion);

  	
  	glutMainLoop();
}

void clavier( unsigned char touche, int x, int y)
{
	switch( touche )
	{
		case 'p':
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glutPostRedisplay();
			break;
		case 'f':
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glutPostRedisplay();
			break;
		case 's':
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			glutPostRedisplay();
			break;
		case 'u':
			zoom++;
			reshape(200*zoom, 200*zoom);
			glutPostRedisplay();
			break;
		case 'd':
			glEnable ( GL_DEPTH_TEST ) ;
			glutPostRedisplay();
			break ;
		case 'D':
			glDisable ( GL_DEPTH_TEST ) ;
			glutPostRedisplay();
			break ;
		case 'q':
			exit(0);
	}
}
	
void affichage()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
  	
  /*	glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0); 	
		glVertex2f(-0.5,-0.5);
		
		glColor3f(0.0,1.0,0.0);	
		glVertex2f(0.5,-0.5);
		
		glColor3f(0.0,0.0,1.0);
		glVertex2f(0.5,0.5);
		
		glColor3f(1.0,1.0,1.0);
		glVertex2f(-0.5,0.5);
  	glEnd();*/
  	
  	point p [8]=
  	{
		{ -0.5 , -0.5 , 0.5 ,1.0 ,0.0 ,0.0},
		{ -0.5 , 0.5 , 0.5 ,0.0 ,1.0 ,0.0},
     	{ 0.5 , 0.5 , 0.5 ,0.0 ,0.0 ,1.0},
     	{ 0.5 , -0.5 , 0.5 ,1.0 ,1.0 ,1.0} ,
     	{ -0.5 , -0.5 , -0.5 ,1.0 ,0.0 ,0.0},
     	{ -0.5 , 0.5 , -0.5 ,0.0 ,1.0 ,0.0},
     	{ 0.5 , 0.5 , -0.5 ,0.0 ,0.0 ,1.0},
     	{ 0.5 , -0.5 , -0.5 ,1.0 ,1.0 ,1.0}
     };
     
	int f [6][4]=
	{ 
		{0 ,1 ,2 ,3}, 
		{3 ,2 ,6 ,7}, 
		{4 ,5 ,6 ,7},
		{0 ,1 ,5 ,4},
		{1 ,5 ,6 ,2},
		{0 ,4 ,7 ,3}
	};
  	
  	int i, j;
	for ( i =0; i <6; i++) // 6 faces
	{
		glBegin( GL_POLYGON );
			for ( j=0; j<4; j++) // 4 points
			{
				glColor3f( p[f[i][j]].r , p[f[i][j]].g , p[f[i][j]].b );
				glVertex3f( p[f[i][j]].x , p[f[i][j]].y , p[f[i][j]].z );
			}
		glEnd();
	}
	
	glLoadIdentity();
	glRotatef(angley, 1.0, 0.0, 0.0);
	glRotatef(anglex, 0.0, 1.0, 0.0);

  	glFlush();
  	glutSwapBuffers();
}

void mouse( int button , int state , int x , int y )
{
	/* si on appuie sur le bouton gauche */
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		presse = 1; /* le booleen presse passe a 1 ( vrai ) */
		xold = x ; /* on sauvegarde la position de la souris */
		yold = y ;
	}
	/* si on relache le bouton gauche */
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_UP )
		presse =0; /* le booleen presse passe a 0 ( faux ) */
}

void mousemotion ( int x , int y )
{
	if ( presse ) /* si le bouton gauche est presse */
	{
		/* on modifie les angles de rotation de l ’ objet
		en fonction de la position actuelle de la souris et de la derniere
		position sauvegardee */
		anglex = anglex +( x - xold ) ;
		angley = angley +( y - yold ) ;
		glutPostRedisplay();
	}
	xold = x ; // sauvegarde des valeurs courante de le position de la souris
	yold = y ;
}

void reshape ( int x , int y )
{
	if (x < y )
		glViewport (0 ,( y - x ) /2 ,x , x ) ;
	else
		glViewport (( x - y ) /2 ,0 , y , y ) ;
}
