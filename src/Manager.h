#ifndef _MANAGER_H___
#define _MANAGER_H___

#include "utils/gl_canvas2d.h"
#include "motor/Motor.h"
#include "utils/Frames.h"
#include <Windows.h>
#include <mmsystem.h>





class Manager {
protected:
    int w, h;
    Motor* motor;
    Frames* frames;
    bool _3d = false;
public:
    Manager(int _w, int _h);
    void onKey(int key);
    void render();
    void playAudio(const char* filename);
};



















#endif