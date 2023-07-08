#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils/gl_canvas2d.h"
#include "motor/Motor.h"

int opcao  = 1;
int screenWidth = 500, screenHeight = 500;
int mouseX, mouseY;

Motor *motor = nullptr;

void render(){
   CV::translate(screenWidth/2, screenHeight/2);
   if(opcao == 1){
      motor->_2dRender();
   }
   else if(opcao == 2){
      motor->_3dRender();
   }
}


void keyboard(int key){
   if(key == '1'){
      opcao = 1;
   }
   else if(key == '2'){
      opcao = 2;
   }
}


void keyboardUp(int key){

}


void mouse(int button, int state, int wheel, int direction, int x, int y){
   mouseX = x;
   mouseY = y;
}

int main(void){
   motor = new Motor(1000, screenWidth, screenHeight);
   CV::init(&screenWidth, &screenHeight, "Motor");
   CV::run();;
}
