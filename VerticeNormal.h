#ifndef __Pr3__VerticeNormal__
#define __Pr3__VerticeNormal__

#include <iostream>
#include "PV3D.h"

class VerticeNormal{
    private:
        int indiceVertice;
        int indiceNormal;
    
    public:
    VerticeNormal(int _indiceVertice, int _indiceNormal){
        this->indiceVertice= _indiceVertice;
        this->indiceNormal = _indiceNormal;
    }
    void setIndiceVertice(int _indiceVertice);
    void setIndiceNormal(int _indiceNormal);
    int getIndiceVertice();
    int getIndiceNormal();

};

#endif /* defined(__Pr3__VerticeNormal__) */
