/* FREEGLUT WINDOWS LIBRARIES */
/*#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>*/

/* GLUT XCODE LIBRARY (MAC OS X)*/
#include <GLUT/glut.h>
#include <math.h>
#include "PV3D.h"
#ifndef LAPIZ_H
#define LAPIZ_H

class Lapiz{

	 private:
        PV3D* currentPosition;
        GLfloat currentDirection;
			  
     public: 
        Lapiz();
        Lapiz(PV3D* position, GLfloat direction);
        ~Lapiz();
        void moveTo(PV3D* p, bool draw);
        void turnTo(GLfloat angle);
        void turn(GLfloat angle);
        void forward(GLfloat dist, bool draw);
        PV3D* getCurrentPosition();
        GLfloat getCurrentDirection();
};
#endif