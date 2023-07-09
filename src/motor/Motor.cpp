#include "Motor.h"

Vector3 inicio = Vector3(0.0f, 0.0f, -1000.0f); //evitar origem

void Motor::build2d(){

    manivela.x[0] = -manivela.r;
    manivela.x[1] = manivela.r;
    manivela.x[2] = manivela.r/4.0f;
    manivela.x[3] = -manivela.r/4.0f;

    manivela.y[0] = -manivela.r;
    manivela.y[1] = -manivela.r;
    manivela.y[2] = manivela.r;
    manivela.y[3] = manivela.r;

    pistao.x[0] = -25.0f;
    pistao.x[1] = 25.0f;
    pistao.x[2] = 25.0f;
    pistao.x[3] = -25.0f;

    pistao.y[0] = 150.0f;
    pistao.y[1] = 150.0f;
    pistao.y[2] = 200.0f;
    pistao.y[3] = 200.0f;
}

void Motor::build3d(){
    Forma f0 = Forma(dim);
    f0.cilindro(manivela.r, 100); //manivela
    Forma f1 = Forma(dim);
    f1.disco(manivela.r*2+10); //conector da manivela 1
    Forma f2 = Forma(dim);
    f2.cilindro(manivela.r*2, manivela.r*2); //pistao 1
    Forma f3 = Forma(dim);
    f3.disco(manivela.r*2+10); //conector da manivela 2
    Forma f4 = Forma(dim);
    f4.cilindro(manivela.r*2, manivela.r*2); //pistao 2

    Forma f5 = Forma(dim); //biela 1
    f5.cilindro(manivela.r/4, sqrt(pow((oposto/tan(PI/4.0f)), 2) + pow(oposto, 2))); //parafuso 1

    Forma f6 = Forma(dim); //biela 2
    f6.cilindro(manivela.r/4, sqrt(pow((oposto/tan(PI/4.0f)), 2) + pow(oposto, 2))); //parafuso 2

    _3d.push_back(f0);
    _3d.push_back(f1);
    _3d.push_back(f2);
    _3d.push_back(f3);
    _3d.push_back(f4);
    _3d.push_back(f5);
    _3d.push_back(f6);

}

Motor::Motor(int rpm, int _w, int _h){
    rot = 0.0f;
    manivela.r = 30.0f;
    w = _w;
    h = _h;
    RPM = rpm;
    ang = 0.0f;
    ligado = false;
    build2d();
    build3d();
}

void Motor::chave(){
    ligado = !ligado;
}



void Motor::_2dRender(){
    float dd = _3d[0].m.DIM;
    for(int i = 0; i < _3d.size(); i++){
        for(int j = 0; j < dd; j++){
            delete[] _3d[i].m.desc[j];
            delete[] _3d[i].m.proj[j];
        }
    delete[] _3d[i].m.desc;
    delete[] _3d[i].m.proj;
    }

    _3d.clear();
    build3d();
    

    Matriz t1[] = {
        Matriz().rot(0.0f, PI/2.0f, ang),
        Matriz().transl(inicio.x, inicio.y, inicio.z),
        Matriz().esc(1.0f, 1.0f, 0.0f)
    };
    _3d[1].m.transform(t1, 2);


    Matriz t2[] = {
        Matriz().rot(PI/4.0f, 0.0f, 0.0f),
        Matriz().esc(1.0f, 1.0f, 0.0f),
        Matriz().transl((oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, oposto + inicio.y+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, 0.0f),
    };
    _3d[2].m.transform(t2, 3);

    Matriz t4[] = {
        Matriz().rot(-PI/4.0f, 0.0f, 0.0f),
        Matriz().esc(1.0f, 1.0f, 0.0f),
        Matriz().transl(-40.0f-(oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, +40.0f + oposto + inicio.y+manivela.r*2*(sin(ang)+cos(ang))/2.0f, 0.0f),
    };
    _3d[4].m.transform(t4, 3);


    float _x = inicio.x+manivela.r*2*+cos(ang) - (oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*+(sin(ang)+cos(ang))/2.0f; //distancia em x do pistao ao parafuso
    float _y = inicio.y+manivela.r*2*+sin(ang) - (oposto + inicio.y+manivela.r*2*-(sin(ang)+cos(ang))/2.0f); //distancia em y do pistao ao parafuso
    float angle = atan(_y/_x);

    Matriz t5[] = {
        Matriz().rot(PI, 0.0f, 0.0f),
        Matriz().rot(angle, 0.0f, 0.0f),
        Matriz().transl((oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, oposto + inicio.y+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, 0.0f),
        Matriz().esc(1.0f, 1.0f, 0.0f)
    };
    _3d[5].m.transform(t5, 4);

    Matriz t6[] = {
        Matriz().rot(0.0f, 0.0f, 0.0f),
        Matriz().rot(-angle, 0.0f, 0.0f),
        Matriz().transl(-(oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, oposto + inicio.y+manivela.r*2*(sin(ang)+cos(ang))/2.0f, 0.0f),
        Matriz().esc(1.0f, 1.0f, 0.0f)

    };
    _3d[6].m.transform(t6, 4);

    _3d[2].render();

    _3d[3].render();
    _3d[0].render();

    _3d[6].render();
    _3d[4].render();

    _3d[5].render();
    _3d[1].render();
}


void Motor::_3dRender(){
    float dd = _3d[0].m.DIM;
    if(dd != this->dim){
        for(int i = 0; i < _3d.size(); i++){
            for(int j = 0; j < dd; j++){
                delete[] _3d[i].m.desc[j];
                delete[] _3d[i].m.proj[j];
            }
        delete[] _3d[i].m.desc;
        delete[] _3d[i].m.proj;
        }
    
        _3d.clear();
        build3d();
    }
    Matriz look = Matriz().lookat(Vector3(500.0f*cos(rot), 0.0f, -800.0f+inicio.z+500*sin(rot)), Vector3(inicio.x, inicio.y + 100.0f, inicio.z), Vector3(0, 1, 0));

    Matriz t0[] = {
        Matriz().rot(0.0f, PI/2.0f, ang),
        Matriz().transl(inicio.x, inicio.y, inicio.z),
        look,
        Matriz().persp(local),
    };
    _3d[0].m.transform(t0, 4);

    Matriz t1[] = {
        Matriz().rot(0.0f, PI/2.0f, ang),
        Matriz().transl(inicio.x, inicio.y, inicio.z),
        look,
        Matriz().persp(local),
    };
    _3d[1].m.transform(t1, 4);


    Matriz t2[] = {
        Matriz().rot(PI/4.0f, 0.0f, 0.0f),
        Matriz().transl((oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, oposto + inicio.y+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, inicio.z),
        look,
        Matriz().persp(local),
    };
    _3d[2].m.transform(t2, 4);

    Matriz t3[] = {
        Matriz().rot(0.0f, PI/2.0f, ang),
        Matriz().transl(inicio.x, inicio.y, inicio.z-100.0f),
        look,
        Matriz().persp(local),
    };
    _3d[3].m.transform(t3, 4);

    Matriz t4[] = {
        Matriz().rot(-PI/4.0f, 0.0f, 0.0f),
        Matriz().transl(-manivela.r-(oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, +manivela.r*2 + oposto + inicio.y+manivela.r*2*(sin(ang)+cos(ang))/2.0f, inicio.z-100.0f),
        look,
        Matriz().persp(local),
    };
    _3d[4].m.transform(t4, 4);


    float _x = inicio.x+manivela.r*2*+cos(ang) - (oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*+(sin(ang)+cos(ang))/2.0f; //distancia em x do pistao ao parafuso
    float _y = inicio.y+manivela.r*2*+sin(ang) - (oposto + inicio.y+manivela.r*2*-(sin(ang)+cos(ang))/2.0f); //distancia em y do pistao ao parafuso
    float angle = atan(_y/_x);

    Matriz t5[] = {
        Matriz().rot(PI, 0.0f, 0.0f),
        Matriz().rot(angle, 0.0f, 0.0f),
        Matriz().transl((oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, oposto + inicio.y+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, inicio.z),
        look,
        Matriz().persp(local),
    };
    _3d[5].m.transform(t5, 5);

    Matriz t6[] = {
        Matriz().rot(0.0f, 0.0f, 0.0f),
        Matriz().rot(-angle, 0.0f, 0.0f),
        Matriz().transl(-(oposto/tan(PI/4.0f))+inicio.x+manivela.r*2*-(sin(ang)+cos(ang))/2.0f, oposto + inicio.y+manivela.r*2*(sin(ang)+cos(ang))/2.0f, inicio.z-100.0f),
        look,
        Matriz().persp(local),
    };
    _3d[6].m.transform(t6, 5);

    _3d[2].render();

    _3d[3].render();
    _3d[0].render();

    _3d[6].render();
    _3d[4].render();

    _3d[5].render();
    _3d[1].render();
}

