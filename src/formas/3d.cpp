#include "3d.h"

Forma::Forma(int DIM){
    m.init(DIM);
}


void Forma::render() {
    for(int x=0; x < this->m.DIM; x++){
        for(int z=0; z < this->m.DIM; z++){
            CV::line(this->m.proj[x][z].x, this->m.proj[x][z].y, this->m.proj[x+1][z].x, this->m.proj[x+1][z].y);
            CV::line(this->m.proj[x][z].x, this->m.proj[x][z].y, this->m.proj[x][z+1].x, this->m.proj[x][z+1].y);
        }
    }
}

void Forma::esfera(int r){
    float theta = 0;

    for(int i = 0; i <= this->m.DIM; i++){
        float phi = 0;
        for(int j = 0; j <= this->m.DIM; j++){
            float x = r*cos(theta)*sin(phi);
            float y = r*sin(theta)*sin(phi);
            float z = r*cos(phi);
            this->m.desc[i][j] = Vector3(x, y, z);
            phi += PI/this->m.DIM;
        }
        theta += 2*PI/this->m.DIM;
    }
}

void Forma::disco(int r){

    float theta = 0;

    for(int i = 0; i <= this->m.DIM; i++){
        float phi = 0;
        for(int j = 0; j <= this->m.DIM; j++){
            float z = r*cos(theta)*sin(phi);
            float y = r*sin(theta)*sin(phi);
            float x = 1;
            this->m.desc[i][j] = Vector3(x, y, z);
            phi += PI/this->m.DIM;
        }
        theta += 2*PI/this->m.DIM;
    }
}

void Forma::cilindro(int r, float h){
    float theta = 0;
    for(int i = 0; i <= this->m.DIM; i++){
        for(int j = 0; j <= this->m.DIM; j++){
            float z = r*cos(theta);
            float y = r*sin(theta);
            float x = (h/this->m.DIM) * j;
            this->m.desc[i][j] = Vector3(x, y, z);
        }
        theta += 2*PI/this->m.DIM;
    }
}

void Forma::placa(int r, float h){
    float theta = 0;
    for(int i = 0; i <= this->m.DIM; i++){
        for(int j = 0; j <= this->m.DIM; j++){
            float z = 1;
            float y = r*sin(theta);
            float x = (h/this->m.DIM) * j;
            this->m.desc[i][j] = Vector3(x, y, z);
        }
        theta += 2*PI/this->m.DIM;
    }
}



