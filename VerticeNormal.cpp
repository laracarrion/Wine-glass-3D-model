#include "VerticeNormal.h"

void VerticeNormal::setIndiceVertice(int _indiceVertice){
    this->indiceVertice = _indiceVertice;
}
void VerticeNormal::setIndiceNormal(int _indiceNormal){
    this->indiceNormal = _indiceNormal;
}

int VerticeNormal::getIndiceVertice(){
    return this->indiceVertice;
}
int VerticeNormal::getIndiceNormal(){
    return this->indiceNormal;
}
