#include "PV3D.h"
#include <math.h>

void PV3D::setCoordenadaX(GLfloat _x){
    this->x = _x;
}
void PV3D::setCoordenadaY(GLfloat _y){
    this->y = _y;
}
void PV3D::setCoordenadaZ(GLfloat _z){
    this->z = _z;
}

GLfloat PV3D::getCoordenadaX(){
    return this->x;
}
GLfloat PV3D::getCoordenadaY(){
    return this->y;
}
GLfloat PV3D::getCoordenadaZ(){
    return this->z;
}

GLfloat PV3D::productoEscalar(PV3D* _punto){
    GLfloat productoCoordenadasX = this->x * _punto->getCoordenadaX();
    GLfloat productoCoordenadasY = this->y * _punto->getCoordenadaY();
    GLfloat productoCoordenadasZ = this->z * _punto->getCoordenadaZ();
    return productoCoordenadasX + productoCoordenadasY + productoCoordenadasZ;
}

void PV3D::normalizarVector(){
    this->x = this->x/(sqrt(pow(this->x, 2) + pow(this->y, 2) + (pow(this->z, 2))));
    this->y = this->y/(sqrt(pow(this->x, 2) + pow(this->y, 2) + (pow(this->z, 2))));
    this->z = this->z/(sqrt(pow(this->x, 2) + pow(this->y, 2) + (pow(this->z, 2))));
    
}

PV3D* PV3D::calcularVector(PV3D* _punto){
    PV3D* vectorCalculado = new PV3D;
    vectorCalculado->setCoordenadaX(_punto->getCoordenadaX() - this->x);
    vectorCalculado->setCoordenadaY(_punto->getCoordenadaY() - this->y);
    vectorCalculado->setCoordenadaZ(_punto->getCoordenadaZ() - this->z);
    return vectorCalculado;
}

PV3D* PV3D::productoVectorial(PV3D* v){
    PV3D* vectorResultado = new PV3D;
    vectorResultado->setCoordenadaX ((this->y * v->getCoordenadaZ()) - (this->z*v->getCoordenadaY()));
    vectorResultado->setCoordenadaY ((this->z * v->getCoordenadaX()) - (this->x*v->getCoordenadaZ()));
    vectorResultado->setCoordenadaZ ((this->x * v->getCoordenadaY()) - (this->y*v->getCoordenadaX()));
    return vectorResultado;
}
