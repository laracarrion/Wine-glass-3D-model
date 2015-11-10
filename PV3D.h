#ifndef __Pr3__PV3D__
#define __Pr3__PV3D__

/* FREEGLUT WINDOWS LIBRARIES */
//#include <OpenGL/glext.h>
//#include <OpenGL/gl.h>
//#include <OpenGL/glu.h>

#include <iostream>
#include <GLUT/glut.h>


class PV3D{

    private:
        GLfloat x;
        GLfloat y;
        GLfloat z;
        int pv;

    public:
        PV3D(){
            this->x = 0.0;
            this->y = 0.0;
            this->z = 0.0;
        }
        PV3D(GLfloat _x, GLfloat _y, GLfloat _z, int _pv){
            this->x= _x;
            this->y= _y;
            this->z= _z;
            this->pv= _pv;
        }
        void setCoordenadaX(GLfloat _x);
        void setCoordenadaY(GLfloat _y);
        void setCoordenadaZ(GLfloat _z);
    
        GLfloat getCoordenadaX();
        GLfloat getCoordenadaY();
        GLfloat getCoordenadaZ();
    
        GLfloat productoEscalar(PV3D* _punto);
        void normalizarVector();
        PV3D* calcularVector(PV3D* _punto);
    
        PV3D* productoVectorial(PV3D* v);
        int getPv(){
            return this->pv;
        }
    

};

#endif /* defined(__Pr3__PV3D__) */
