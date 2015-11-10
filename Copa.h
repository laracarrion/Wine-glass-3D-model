#ifndef __Pr3__Copa__
#define __Pr3__Copa__

#include <iostream>
#include "Malla.h"

class Copa: public Malla{
    
    private:
        int nP;//5 (pentágono) /100 (circunferencia) (número de lados de los polígonos de aproximación)
        int nQ;//50 (número de rodajas del cuenco)
    
    public:
        Copa(){
            nP=100;
            nQ=49;
            numVertices = 3* nP + nP * nQ; 
            numNormales = 2* nP + nP * nQ;
            numCaras = numNormales;
            perfil = new PV3D*[numVertices];
            vertices = new PV3D*[numVertices];
            normales = new PV3D*[numNormales];
            caras = new Cara*[numCaras];
            
        }
        void construirRodajas(int &compMeter, bool modo_armazon);
        void trazarRodaja(GLfloat radio, PV3D* centro, int &compMeter);
        void drawRodaja(int compMeter, bool modo_armazon);
        void crearCuenco(int compMeter, bool modo_armazon);
        void hazMallaCopa();
        PV3D** getNormales(){return this->normales;}
        Cara** getCaras(){return this->caras;}
        int getNumCaras(){return this->numCaras;}
        void setNormales(PV3D** _normales){
            this->normales = _normales;
        }
       
    
};

#endif /* defined(__Pr3__Copa__) */
