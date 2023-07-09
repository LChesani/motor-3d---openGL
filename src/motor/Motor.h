#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "../formas/3d.h"
#include <vector>

class Manivela{
    public:
        float r;
        float x[4];
        float y[4];
};

class Pistao{
    public:
        float x[4];
        float y[4];
};

class Motor{

protected:
    float oposto = 250.0f;
    float local = -800.0f;
    int x, y;
    int w, h;
    bool ligado;
    std::vector <Forma> _3d;
    void build3d();
    void build2d();
    Manivela manivela;
    Pistao pistao;
public:
    int dim = 20;
    float ang;
    int RPM;
    float rot;
    Motor(int rpm, int _w, int _h);
    void chave();
    void _2dRender();
    void _3dRender();
};








#endif