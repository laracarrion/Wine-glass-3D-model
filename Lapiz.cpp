#include <math.h>
#include "Lapiz.h"
#include <GLUT/glut.h>

Lapiz::Lapiz(){
	currentPosition = new PV3D(0.0, 0.0, 0.0, 0);
	currentDirection= 0.0;
	
}

Lapiz::Lapiz(PV3D* position, GLfloat direction){
	currentPosition = position;
	currentDirection = direction;
}

Lapiz::~Lapiz(){
}

void Lapiz::moveTo(PV3D* p, bool draw){
	currentPosition = p;
	if(draw)
		glVertex3f(currentPosition->getCoordenadaX(),currentPosition->getCoordenadaY(), currentPosition->getCoordenadaZ());
}
	
void Lapiz::turnTo(GLfloat angle){
	currentDirection = angle;

}

void Lapiz::turn(GLfloat angle){
	currentDirection+=angle;
}
	
void Lapiz::forward(GLfloat dist, bool draw){
	GLdouble x = currentPosition->getCoordenadaX();
    GLdouble z = currentPosition->getCoordenadaZ();
    x+=dist*cos(currentDirection);
    z+= dist*sin(currentDirection);
    currentPosition->setCoordenadaX(x);
    currentPosition->setCoordenadaZ(z);	
	if(draw)
		glVertex3f(currentPosition->getCoordenadaX(),currentPosition->getCoordenadaY(), currentPosition->getCoordenadaZ());
}


PV3D* Lapiz::getCurrentPosition(){
	return currentPosition;
}

GLfloat Lapiz::getCurrentDirection(){
	return currentDirection;
}