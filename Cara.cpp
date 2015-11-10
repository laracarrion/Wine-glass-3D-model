#include "Cara.h"


Cara::Cara(int _numVertices, VerticeNormal** _normalesVertices){
    this->numVertices = _numVertices;
    this->normalesVertices = _normalesVertices;
}
void Cara::setNumVertices(int _numVertices){
    this->numVertices = _numVertices;
}

int Cara::getNumVertices(){
    return this->numVertices;
}

VerticeNormal** Cara::getNormalesVertices(){
    return this->normalesVertices;
}

int Cara::getIndiceNormalK(int indiceVertice){
    return this->normalesVertices[indiceVertice]->getIndiceNormal();
}

int Cara::getIndiceVerticeK(int indiceVertice){
    return this->normalesVertices[indiceVertice]->getIndiceVertice();
}
