#include "Toro.h"
using namespace std;
#define USE_MATH_DEFINES
#include <math.h>
void Toro::creaToro() {
    
	R = 1;
	r = 5;
	GLdouble inc=(2*M_PI/nP);
    for (int i = 0; i < nP; i++) {
		perfil[i] = new PV3D(R*cos(2*M_PI -i*inc), R*sin(2*M_PI -i*inc),0,1);
		perfil[nVertices] = new PV3D(R*cos(2*M_PI -i*inc), R*sin(2*M_PI -i*inc),0,1);
		nVertices++;
	}
	aplica(0.0, perfil);
	for (GLdouble t = 2 * M_PI / nQ; t < 2 * M_PI; t += 2 * M_PI / nQ) {
		aplica(t, perfil);
		creaCarasLaterales(nP);
	}
    
}

void Toro::aplica(GLdouble t, PV3D** perfil) {
    
	PV3D* T = new PV3D(-r*sin(t), 0, r*cos(t), 0);
	T->normalizarVector();
    
	PV3D* B = new PV3D(0, -(r*r), 0, 0);
	B->normalizarVector();
    
	PV3D* N = T->productoVectorial(B);
    
	GLdouble M[4][4];
	M[0][0] = N->getCoordenadaX();
    M[1][0] = N->getCoordenadaY();
    M[2][0] = N->getCoordenadaZ();
    M[3][0] = 0;
	M[0][1] = B->getCoordenadaX();
    M[1][1] = B->getCoordenadaY();
    M[2][1] = B->getCoordenadaZ();
    M[3][1] = 0;
    
	M[0][2] = T->getCoordenadaX();
    M[1][2] = T->getCoordenadaY();
    M[2][2] = T->getCoordenadaZ();
    M[3][2] = 0;
	M[0][3] = r*cos(t);
    M[1][3] = 0;
    M[2][3] = r*sin(t);
    M[3][3] = 1;
    
    
    
	for (int i = 0; i < nP; i++) {
        GLdouble newX, newY, newZ;
        int newEsPunto;
        newX = M[0][0] * perfil[i]->getCoordenadaX() +  M[0][1] * perfil[i]->getCoordenadaY() +  M[0][2] * perfil[i]->getCoordenadaZ() +  M[0][3]* perfil[i]->getPv();
        newY = M[1][0] * perfil[i]->getCoordenadaX() +  M[1][1] * perfil[i]->getCoordenadaY() +  M[1][2] * perfil[i]->getCoordenadaZ() +  M[1][3]* perfil[i]->getPv();
        newZ = M[2][0] * perfil[i]->getCoordenadaX() +  M[2][1] * perfil[i]->getCoordenadaY() +  M[2][2] * perfil[i]->getCoordenadaZ() +  M[2][3]* perfil[i]->getPv();
        newEsPunto = M[3][0] * perfil[i]->getCoordenadaX() +  M[3][1] * perfil[i]->getCoordenadaY() +  M[3][2] * perfil[i]->getCoordenadaZ() +  M[3][3]* perfil[i]->getPv();
        
        PV3D** nuevoPerfil = new PV3D*[nP];
        nuevoPerfil[i] = new PV3D(newX, newY, newZ, newEsPunto);
        
        vertices[nVertices] = nuevoPerfil[i];
        nVertices++;
	}
	
	delete T;
	delete B;
	delete N;
}


void Toro::creaCarasLaterales(int nP) {
    for (int j = 0 ; j < nP; j++) {
        int indiceVertice = nVertices - 2*nP + j;
        int indiceCara = 0;
        VerticeNormal** vn = new VerticeNormal*[4];
        if (j + 1 != nP) {
            vn[0] = new VerticeNormal(indiceVertice, indiceCara);
            vn[3] = new VerticeNormal(indiceVertice + nP, indiceCara);
            vn[2] = new VerticeNormal(indiceVertice + nP + 1, indiceCara);
            vn[1] = new VerticeNormal(indiceVertice + 1, indiceCara);
        } else { // Ultima cara
            vn[0] = new VerticeNormal(indiceVertice, indiceCara);
            vn[3] = new VerticeNormal(indiceVertice + nP, indiceCara);
            vn[2] = new VerticeNormal(indiceVertice + 1, indiceCara);
            vn[1] = new VerticeNormal(indiceVertice - nP + 1, indiceCara);
        }
        caras[nCaras] = new Cara(4, vn);
        nCaras++;
        nNormales++;
        indiceCara++;
    }

    
}

Toro::~Toro(void)
{
}

void Toro::drawMallaToro(bool modo_armazon){
	PV3D** vertices = this->vertices;
    for (int i=0; i<numCaras; i++) {
        if(modo_armazon){
            glLineWidth(1.0);
            glBegin(GL_LINE_LOOP);
            for (int j=0; j<caras[i]->getNumVertices(); j++) {
                int iN=caras[i]->getIndiceNormalK(j);
                int iV=caras[i]->getIndiceVerticeK(j);
                //glNormal3f(normales[iN]->getCoordenadaX(),normales[iN]->getCoordenadaY(),normales[iN]->getCoordenadaZ());
                glVertex3f(vertices[iV]->getCoordenadaX(),vertices[iV]->getCoordenadaY(), vertices[iV]->getCoordenadaZ());
            }
            
            glEnd();
        }
        else{
            glLineWidth(1.0);
            glBegin(GL_POLYGON);
            for (int j=0; j<caras[i]->getNumVertices(); j++) {
                int iN=caras[i]->getIndiceNormalK(j);
                int iV=caras[i]->getIndiceVerticeK(j);
                //glNormal3f(normales[iN]->getCoordenadaX(),normales[iN]->getCoordenadaY(),normales[iN]->getCoordenadaZ());
                glVertex3f(vertices[iV]->getCoordenadaX(),vertices[iV]->getCoordenadaY(), vertices[iV]->getCoordenadaZ());
            }
            
            glEnd();
        }
        
        
    }
}