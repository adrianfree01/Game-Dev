#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "engine.h"

void windowLoop(struct engineStruct* windowPtr){
    while(!glfwWindowShouldClose(windowPtr->window)) {
        glfwPollEvents();
    }
}

int createWindow(int width, int height, char* windowName, struct engineStruct* windowPtr) {

    if(!glfwInit())
        return 0;
    GLFWwindow* window = glfwCreateWindow(width, height, windowName, NULL, NULL); 
    if(!window) {
        glfwTerminate();
        return 0;
    }
    windowPtr->window = window;
    return 1;
}

void destroyWindow(struct engineStruct* windowPtr){
    glfwDestroyWindow(windowPtr->window);
    glfwTerminate();
    windowPtr->window = NULL;
    return;
}