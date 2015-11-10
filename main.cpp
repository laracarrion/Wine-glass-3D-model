/* FREEGLUT WINDOWS LIBRARIES */
/*#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>*/
//#include <OpenGL/glext.h>
//#include <OpenGL/gl.h>
//#include <OpenGL/glu.h>
//#include <GL/glut.h>*/

/* GLUT XCODE LIBRARIES (MAC OS X)*/
#include <GLUT/glut.h>
#include <iostream>
#include "Malla.h"
#include "Copa.h"
#include "Toro.h"
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters

GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;


GLfloat xAngle = 0.0, yAngle = 0.0, zAngle = 0.0;
bool pintando_normales = false;
bool modo_armazon = false; //GL_LINE_LOOP
Malla* malla = new Malla();
Copa* copa = new Copa();

Toro* toro = new Toro();
void initGL() {
    
	glClearColor(0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);    

    // Light0
    glEnable(GL_LIGHT0);
    GLfloat d[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[]={25.0, 25.0, 0.0, 1.0};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	// buildSceneObjects();

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);
    
 }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.1f,1.1f,1.1f);   
    // Drawing axes (ejes de coordenadas)
    glBegin( GL_LINES );
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);	     
	 
		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);	 
	 
		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);	     
	glEnd();
    
    glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(xAngle, 1.0, 0.0, 0.0); // Eje X
	glRotatef(yAngle, 0.0, 1.0, 0.0); // Eje Y
	glRotatef(zAngle, 0.0, 0.0, 1.0); // Eje Z
    
    int compMeter =0;
    glColor3f(0.0,0.0,1.0);
    copa->construirRodajas(compMeter, modo_armazon);
    copa->crearCuenco(compMeter, modo_armazon);
    copa->hazMallaCopa();
    PV3D** normalesCopa = copa->getNormales();
    for (int i=0; i<copa->getNumCaras(); i++){
        normalesCopa[i] =copa->normalCaraNewell(copa->getCaras()[i]);
    }
    copa->setNormales(normalesCopa);
    copa->dibuja(modo_armazon);
    
    if(pintando_normales){
        copa->dibujarNormales();
    }
    
    toro->drawMallaToro(modo_armazon);
    glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
            
        case 97:
            cout<<"Tecla 'a' pulsada"<<endl;
            cout<<"Rotación eje X a la izquierda"<<endl;
            xAngle += 10.0;
            break;
        
        case 122:
            cout<<"Tecla 'z' pulsada"<<endl;
            cout<<"Rotación eje X a la derecha"<<endl;
            xAngle -= 10.0;
            break;
            
        case 115:
            cout<<"Tecla 's' pulsada"<<endl;
            cout<<"Rotación eje Y a la izquierda"<<endl;
            yAngle+=10.0;
            break;
            
        case 120:
            cout<<"Tecla 'x' pulsada"<<endl;
            cout<<"Rotación eje Y a la derecha"<<endl;
            yAngle-=10.0;
            break;
            
        case 100:
            cout<<"Tecla 'd' pulsada"<<endl;
            cout<<"Rotación eje Z a la izquierda"<<endl;
            zAngle+=10.0;
            break;
            
        case 99:
            cout<<"Tecla 'c' pulsada"<<endl;
            cout<<"Rotación eje Z a la derecha"<<endl;
            zAngle-=10.0;
            break;
            
        case 103:
            cout<<"Tecla 'g' pulsada"<<endl;
            cout<<"Modo armazón seleccionado"<<endl;
            modo_armazon = true;
            break;
            
        case 104:
            cout<<"Tecla 'h' pulsada"<<endl;
            cout<<"Modo relleno seleccionado"<<endl;
            modo_armazon = false;
            break;
            
        case 106:
            cout<<"Tecla 'j' pulsada"<<endl;
            cout<<"Modo sin normales seleccionado"<<endl;
            pintando_normales = false;
            break;
            
        case 107:
            cout<<"Tecla 'k' pulsada"<<endl;
            cout<<"Modo con normales seleccionado"<<endl;
            pintando_normales = true;
            break;
            
        
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
        
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

    
	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	
    //glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	system("PAUSE"); 
   
	return 0;
}
