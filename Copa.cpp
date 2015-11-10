#include "Copa.h"
#include "Lapiz.h"
#include <math.h>
using namespace std;


void Copa::construirRodajas(int &compMeter, bool modo_armazon){
    
    trazarRodaja(3.0, new PV3D(0.0, -7.0, 0.0, 0), compMeter);
    drawRodaja(compMeter-nP, modo_armazon);
    
    trazarRodaja(0.5, new PV3D(0.0, -6.0, 0.0, 0), compMeter);
    drawRodaja(compMeter-nP, modo_armazon);
    
    trazarRodaja(0.2, new PV3D(0.0, 3.0, 0.0, 0), compMeter);
    drawRodaja(compMeter-nP, modo_armazon);
}

void Copa::trazarRodaja(GLfloat radio, PV3D* centro, int &compMeter){
    int contComp = 0;
    bool terminado = false;
    GLdouble alfa = (2.0 * M_PI) / nP;
    GLdouble beta = (M_PI - alfa) / 2.0;
    GLdouble gamma = M_PI - beta;
    GLdouble longitud= 2* radio * cos(beta);
    
    Lapiz* l = new Lapiz(new PV3D(centro->getCoordenadaX(), centro->getCoordenadaY(), centro->getCoordenadaZ(), 1), gamma);
    l->forward(radio, false);
    l->turn(beta);
    for (int i = compMeter; i < numVertices; i++) {
        if(!terminado){
            PV3D* p = l->getCurrentPosition();
            perfil[i] = new PV3D(p->getCoordenadaX(), p->getCoordenadaY(), p->getCoordenadaZ(), 1);
            l->turn(alfa);
            l->forward(longitud, false);
            contComp++;
            if(contComp == nP){
                terminado = true;
                compMeter=i+1;
            }
        }
    }
    delete l;    
    
}

void Copa::drawRodaja(int compMeter, bool modo_armazon){
    bool terminado = false;
    int contComp=0;
    if(modo_armazon){
        glBegin(GL_LINE_LOOP);
        for (int i=compMeter; i<=numVertices; i++){
            if(!terminado){
                PV3D* p = perfil[i%numVertices];
                glVertex3f(p->getCoordenadaX(), p->getCoordenadaY(), p->getCoordenadaZ());
                contComp++;
                if(contComp == nP) terminado = true;
            }
        }
        glEnd();
    }
}


void Copa::crearCuenco(int compMeter, bool modo_armazon){
    GLdouble radio = 0.5;
    GLdouble centroY=3.2;
    int incComp= compMeter;
    for (int i=0; i<nQ; i++){
        trazarRodaja(sqrt(radio), new PV3D(0.0, centroY, 0.0, 0), compMeter);
        drawRodaja(incComp, modo_armazon);
        incComp +=nP;
        radio +=0.8;
        centroY+=0.2;
    }
}

void Copa::hazMallaCopa(){
    for (int i = 0; i <2 + nQ; i++) {
		for (int j = 0 ; j < nP; j++) {
			int indiceVertice = i * nP + j;
			int indiceCara = indiceVertice;
			VerticeNormal** vn = new VerticeNormal*[4];
			if (j + 1 != nP) {
				vn[0] = new VerticeNormal(indiceVertice, indiceCara);
				vn[1] = new VerticeNormal(indiceVertice + nP, indiceCara);
				vn[2] = new VerticeNormal(indiceVertice + nP + 1, indiceCara);
				vn[3] = new VerticeNormal(indiceVertice + 1, indiceCara);
			} else { // última cara
				vn[0] = new VerticeNormal(indiceVertice, indiceCara);
				vn[1] = new VerticeNormal(indiceVertice + nP, indiceCara);
				vn[2] = new VerticeNormal(indiceVertice + 1, indiceCara);
				vn[3] = new VerticeNormal(indiceVertice - nP + 1, indiceCara);
			}
			caras[indiceCara] = new Cara(4, vn);
		}
	}
    
}