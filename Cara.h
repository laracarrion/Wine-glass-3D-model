#ifndef __Pr3__Cara__
#define __Pr3__Cara__

#include <iostream>
#include "PV3D.h"
#include "VerticeNormal.h"

class Cara{
    private:
        int numVertices;
        VerticeNormal** normalesVertices;
    
    
    public:
        Cara(int _numVertices, VerticeNormal** _normalesVertices);
        void setNumVertices(int _numVertices);
        int getNumVertices();
        VerticeNormal** getNormalesVertices();
        int getIndiceNormalK(int indiceVertice);
        int getIndiceVerticeK(int indiceVertice);
        


};

#endif /* defined(__Pr3__Cara__) */
