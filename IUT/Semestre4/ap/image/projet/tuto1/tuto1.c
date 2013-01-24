#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

# define PI 3.14159265

void affichage () ;
void clavier ( unsigned char touche , int x , int y ) ;
void reshape ( int x , int y ) ;
void calcTableCosSin() ;

int angle =45;
float Sin[360] , Cos[360];
GLfloat L0pos[]={ 0.0 ,2.0 , -1.0};
GLfloat L0dif[]={ 0.3 ,0.3 ,0.8};
GLfloat L1pos[]={ 2.0 ,2.0 ,2.0};
GLfloat L1dif[]={ 0.5 ,0.5 ,0.5};
GLfloat Mspec[]={0.5 ,0.5 ,0.5};
GLfloat Mshiny =50;


int main ( int argc , char ** argv )
{
/* initialisation de glut et creation de la fenetre */
	glutInit (& argc , argv ) ;
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(400,400);
	glutCreateWindow ( " light1 " ) ;
	
/* precalcul de la table des sinus et cosinus */
	calcTableCosSin() ;
	
/* Initialisation d ' OpenGL */
	glClearColor (0.0 ,0.0 ,0.0 ,0.0) ;
	glColor3f (1.0 ,0.0 ,00) ;
	glEnable( GL_DEPTH_TEST ) ;
	
/* Parametrage des lumieres */
/// Specifiez le mode d ' eclairage en utilisant la constante GL_SMOOTH
	glShadeModel(GL_SMOOTH) ;

/// Initialisation des parametres du modele de lumiere
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE) ;

/// Activez les deux lampes
	glEnable(GL_LIGHTING) ;
	glEnable(GL_LIGHT0) ;
	glEnable(GL_LIGHT1) ;
	
/// Pour la lumiere 0 , initialisez le parametre de diffusion
	glLightfv(GL_LIGHT0,GL_DIFFUSE,L0dif) ;
	
/// Pour la lumiere 0 , initialisez le parametre de la composante speculaire
	glLightfv(GL_LIGHT0,GL_SPECULAR,L0dif) ;
	
/// Effectuez les memes reglages sur la lumiere 1
	glLightfv(GL_LIGHT1,GL_DIFFUSE,L1dif) ;
	glLightfv(GL_LIGHT1,GL_SPECULAR,L1dif) ;
	
/* Parametrage du materiau */
/// Initialisez , pour la face avant et arriere , la composante speculaire dumateriau
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Mspec) ;
	
/// Initialisez , pour la face avant et arriere , le coefficient de brillance du materiau
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Mshiny) ;

/* Mise en place de la perspective */
	glMatrixMode( GL_PROJECTION ) ;
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 0.1, 10.0) ;
	glMatrixMode ( GL_MODELVIEW ) ;

/* Mise en place des fonctions de rappel */
	glutDisplayFunc( affichage );
	glutKeyboardFunc( clavier ) ;
	glutReshapeFunc( reshape ) ;

/* Entree dans la boucle principale */
	glutMainLoop () ;
	return 0;
}

void affichage()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();
	gluLookAt(4.5*Cos[angle], 2.0, 4.5*Sin[angle], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
/// Mise a jour des deux sources lumineuses
	glLightfv ( GL_LIGHT0,GL_POSITION,L0pos ) ;
	glLightfv ( GL_LIGHT1,GL_POSITION,L1pos ) ;
	
/// Affichage de la teiere
	glutSolidTeapot(1.0) ;
	
	glutSwapBuffers();
}

void clavier( unsigned char touche , int x , int y )
{
	switch ( touche )
	{
		case 'z' :         /* increment de l ' angle de position */
			angle +=2;
			if ( angle >=360)
			angle -=360;
			glutPostRedisplay();
			break;
		case 'a' : /* decrement de l ' angle de position */
			angle -=2;
			if ( angle <0)
			angle +=360;
			glutPostRedisplay();
			break ;
		case 'w' : /* Allumer la lampe 0 */
			glEnable(GL_LIGHT0) ;
			glutPostRedisplay();
			break ;
		case 'x' : /* Eteindre la lampe 0 */
			glDisable(GL_LIGHT0) ;
			glutPostRedisplay();
			break ;
		case 'c': /* Allumer la lampe 1 */
			glEnable(GL_LIGHT1) ;
			glutPostRedisplay();
			break ;
		case 'v': /* Eteindre la lampe 0 */
			glDisable(GL_LIGHT1) ;
			glutPostRedisplay();
			break ;
		case 'm': /* increment reflexion speculaire */
			Mspec [0]+=0.1;
			if ( Mspec [0] >1)
				Mspec [0]=1;
			Mspec [1]+=0.1;
			if ( Mspec [1] >1)
				Mspec [1]=1;
			Mspec [2]+=0.1;
			if ( Mspec [2] >1)
				Mspec [2]=1;
	/// Mise a jour des proprietes du materiau
			glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Mspec) ;
			glutPostRedisplay();
			break ;
		case 'l': /* decrement reflexion speculaire du materiau */
			Mspec[0]-=0.1 ;
			if (Mspec[0]<0)
				Mspec[0]=0;
			Mspec[1]-=0.1 ;
			if (Mspec[1]<0)
				Mspec[1]=0 ;
			Mspec[2]-=0.1 ;
			if (Mspec[2]<0)
				Mspec[2]=0 ;
			glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Mspec) ;
			glutPostRedisplay();
			break ;
		case 'j': /* incrementation de la brillance */
			Mshiny -=1;
			if ( Mshiny <0)
				Mshiny =0;
			glMaterialf (GL_FRONT_AND_BACK, GL_SHININESS, Mshiny ) ;
			glutPostRedisplay();
			break ;
		case 'k': /* decrement de la brillance */
			Mshiny+=1 ;
			glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Mshiny) ;
			glutPostRedisplay();
			break ;
		case 'q' :
			exit (0) ;
	}
}

void reshape ( int x , int y )
{
	if(x<y)
		glViewport(0,(y-x)/2,x,x);
	else
		glViewport((x-y)/2,0,y,y);
}

void calcTableCosSin ()
{
	/* calcul du tableau des sinus et cosinus */
	int i ;
	for ( i =0; i <360; i ++)
	{
		Cos [ i ]= cos ((( float ) i ) /180.0* PI ) ;
		Sin [ i ]= sin ((( float ) i ) /180.0* PI ) ;
	}
}
