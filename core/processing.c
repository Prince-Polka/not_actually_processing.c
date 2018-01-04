#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLFW/glfw3.h> // GLFW helper library
typedef char GLchar;
#include "loadStrings.c"
#include "PShader.c"

const double PI = 3.1415926535897;

#define LONG long long int

void setup();
void draw();


int width = 100,
    height = 100,
    loop = 1;

double mouseX,mouseY,pmouseX,pmouseY;

void size(int w, int h){
  width = w;
  height = h;
}

LONG starttime;

LONG millis(){
  return ((glfwGetTimerValue()-starttime)*1000)/glfwGetTimerFrequency();
}

int main(){
    setup();
    GLFWwindow* window;
    if (!glfwInit()) return -1;

    window = glfwCreateWindow(width, height, "processing.c", 0, 0);
    if (!window){glfwTerminate();return -1;}
    glfwMakeContextCurrent(window);

    klistra();

    RENDERER = loadShader("./core/draw.frag","./core/draw.vert");

    shader(RENDERER);

    uniform(vec2,u_resolution,width,height);

    //float po[3] = {640.0f,480.0f,0.0f};
    //uniformarray(vec2,u_resolution,1,&po[0]);

    starttime=glfwGetTimerValue();
    while(!glfwWindowShouldClose(window)) {
      glfwGetCursorPos(window, &mouseX, &mouseY);
      uniform(vec2,u_mouse,mouseX,mouseY);
      draw();
      pmouseX = mouseX;
      pmouseY = mouseY;
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
      glfwWaitEvents();
      glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
