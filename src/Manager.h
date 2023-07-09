#ifndef _MANAGER_H___
#define _MANAGER_H___

#include "utils/gl_canvas2d.h"
#include "motor/Motor.h"
#include "utils/Frames.h"





class Manager {
protected:
    int opcao;
    int w, h;
    Motor* motor;
    Frames* frames;
public:
    Manager(int _w, int _h);
    void onKey(int key);
    void render();

};



















#endif