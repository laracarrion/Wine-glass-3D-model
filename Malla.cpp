#include "Malla.h"
using namespace std;

int Malla::getNumVertices(){
    return this->numVertices;
}
int Malla::getNumNormales(){
    return this->numNormales;
}
int Malla::getNumCaras(){
    return this->numCaras;
}
PV3D** Malla::getVertices(){
    return this->vertices;
}
PV3D** Malla::getNormales(){
    return this->normales;
}
Cara** Malla::getCaras(){
    return this->caras;
}

void Malla::dibuja(bool modo_armazon){
    for (int i=0; i<numCaras; i++) {
        if(modo_armazon){
            glLineWidth(1.0);
            glBegin(GL_LINE_LOOP);
            for (int j=0; j<caras[i]->getNumVertices(); j++) {
                int iN=caras[i]->getIndiceNormalK(j);
                int iV=caras[i]->getIndiceVerticeK(j);
                glNormal3f(normales[iN]->getCoordenadaX(),normales[iN]->getCoordenadaY(),normales[iN]->getCoordenadaZ());
                glVertex3f(perfil[iV]->getCoordenadaX(),perfil[iV]->getCoordenadaY(), perfil[iV]->getCoordenadaZ());
            }
            glEnd();
        }
        else{
            glLineWidth(1.0);
            glBegin(GL_POLYGON);
            for (int j=0; j<caras[i]->getNumVertices(); j++) {
                int iN=caras[i]->getIndiceNormalK(j);
                int iV=caras[i]->getIndiceVerticeK(j);
                glNormal3f(normales[iN]->getCoordenadaX(),normales[iN]->getCoordenadaY(),normales[iN]->getCoordenadaZ());
                glVertex3f(perfil[iV]->getCoordenadaX(),perfil[iV]->getCoordenadaY(), perfil[iV]->getCoordenadaZ());
            }
            glEnd();
        }
    }
}



PV3D* Malla::normalCaraNewell(Cara* cara){
    PV3D* n = new PV3D(0.0, 0.0, 0.0, 0);
    for (int i=0; i<cara->getNumVertices(); i++) {
        PV3D* vertActual= perfil[cara->getIndiceVerticeK(i)];
        PV3D* vertSiguiente= perfil[cara->getIndiceVerticeK((i+1) % cara->getNumVertices())];
        n->setCoordenadaX(n->getCoordenadaX() + ((vertActual->getCoordenadaY() - vertSiguiente->getCoordenadaY()) * (vertActual->getCoordenadaZ() + vertSiguiente->getCoordenadaZ())));
        n->setCoordenadaY(n->getCoordenadaY() + ((vertActual->getCoordenadaZ() - vertSiguiente->getCoordenadaZ()) * (vertActual->getCoordenadaX() + vertSiguiente->getCoordenadaX())));
        n->setCoordenadaZ(n->getCoordenadaZ() + ((vertActual->getCoordenadaX() - vertSiguiente->getCoordenadaX()) * (vertActual->getCoordenadaY() + vertSiguiente->getCoordenadaY())));
    }
    n->normalizarVector();
    return n;
}


void Malla::dibujarNormales() {
	for (int i = 0; i < numCaras; i++) {
        glLineWidth(1.0);
		glColor3f(1.0,1.0,1.0);
        int iN = caras[i]->getIndiceNormalK(0);
        int iV0 = caras[i]->getIndiceVerticeK(0);
        int iV1 = caras[i]->getIndiceVerticeK(1);
        int iV2 = caras[i]->getIndiceVerticeK(2);
        int iV3 = caras[i]->getIndiceVerticeK(3);
        GLfloat x = (perfil[iV0]->getCoordenadaX() + perfil[iV1]->getCoordenadaX() + perfil[iV2]->getCoordenadaX() + perfil[iV3]->getCoordenadaX()) / 4;
        GLfloat y = (perfil[iV0]->getCoordenadaY() + perfil[iV1]->getCoordenadaY() + perfil[iV2]->getCoordenadaY() + perfil[iV3]->getCoordenadaY()) / 4;
        GLfloat z = (perfil[iV0]->getCoordenadaZ() + perfil[iV1]->getCoordenadaZ() + perfil[iV2]->getCoordenadaZ() + perfil[iV3]->getCoordenadaZ()) / 4;
        glBegin(GL_LINE_STRIP);
        glNormal3f(normales[iN]->getCoordenadaX(), normales[iN]->getCoordenadaY(), normales[iN]->getCoordenadaZ());
        glVertex3f(x, y, z);
        glVertex3f(x + normales[iN]->getCoordenadaX(), y + normales[iN]->getCoordenadaY(), z + normales[iN]->getCoordenadaZ());
        glEnd();
    }
}
