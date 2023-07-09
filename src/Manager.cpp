#include "Manager.h"



Manager::Manager(int _w, int _h){
    w = _w;
    h = _h;
    motor = new Motor(100, w, h);
    frames = new Frames();
    opcao = 0;
}

void Manager::onKey(int key){
    if(key == '1'){
        opcao = 0;
        return;
    }
    if(key == '2'){
        opcao = 1;
        return;
    }
    if(key == '='){
        motor->dim += 1;
        return;
    }
    if(key == '-'){
        motor->dim -= 1;
        return;
    }
    if(key == 'w'){
        motor->RPM += 50;
        return;
    }
    if(key == 's'){
        motor->RPM -= 50;
        return;
    }

}

void Manager::render(){
    float fps = frames->getFps();
    char aux[50];
    CV::color(1, 1, 1);

    sprintf(aux, "FPS: %.2f", fps);
    CV::text(-w/2.0f+10, 10-h/2.0f, aux);

    sprintf(aux, "RPM: %d", motor->RPM);
    CV::text(-w/2.0f+10, 25-h/2.0f, aux);

    fps = fps * 60.0f; // frames por minuto
    float step = 2*PI/fps;
    motor->ang += step*motor->RPM;
    motor->rot += step*5.0f;
    if(opcao == 0){
        motor->_2dRender();
    }
    if(opcao == 1){
        motor->_3dRender();
    }
}
