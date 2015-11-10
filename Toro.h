#ifndef __Pr3__Toro__
#define __Pr3__Toro__
#include "Malla.h"

class Toro : public Malla{
    
private:
    int nP;
    int nQ;
    GLdouble R;
    GLdouble r;
   	int nVertices;
	int nCaras;
	int nNormales;
    
public:
	Toro(){
		nP = 8;
		nQ = 64;
	    nVertices =0;
		nCaras=0;
		nNormales=0;
		numVertices = nP * nQ;
		numCaras = nP * nQ;
		vertices= new PV3D*[numVertices];
		caras = new Cara*[numCaras];
		normales = new PV3D*[numCaras];
		perfil = new PV3D*[nP];
        creaToro();
        
	}
    
    void aplica(GLdouble t, PV3D** perfil);
    
    
    void creaToro();
    void creaCarasLaterales(int nP);
    void drawMallaToro(bool modo_armazon);
    
    ~Toro(void);
};

#endif /* defined(__Pr3__Toro__) */
