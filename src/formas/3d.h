#ifndef __3D_H__
#define __3D_H__


#include "../utils/gl_canvas2d.h"
#include "../utils/Matriz.h"
#include <math.h>
#include <time.h>




class Forma{

public:
    float local = -900.0f;
    Coord m;
    Forma(int DIM);
    void render();
    void esfera(int r);
    void disco(int r);
    void cilindro(int r, float h);
    void placa(int r, float h);
};








#endif