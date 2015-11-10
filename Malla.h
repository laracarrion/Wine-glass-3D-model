#ifndef __Pr3__Malla__
#define __Pr3__Malla__

#include <iostream>
#include "PV3D.h"
#include "VerticeNormal.h"
#include "Cara.h"

class Malla{

    protected:
        int numVertices;
        int numNormales;
        int numCaras;
        PV3D** vertices;
        PV3D** perfil;
        PV3D** normales;
        Cara** caras;
    
    public:
        Malla(){}    
        int getNumVertices();
        int getNumNormales();
        int getNumCaras();
        PV3D** getVertices();
        PV3D** getNormales();
        Cara** getCaras();
    
        void dibuja(bool modo_armazon);
        PV3D* normalCaraNewell(Cara* cara);
        void dibujarNormales();

};

#endif /* defined(__Pr3__Malla__) */
