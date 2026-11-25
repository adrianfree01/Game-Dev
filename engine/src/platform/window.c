#include <GLFW/glfw3.h>
#include "engine.h"
#include "window.h"
#include "render.h"

void windowLoop(struct engineStruct* windowPtr){
    while(!glfwWindowShouldClose(windowPtr->window)) {
        glfwPollEvents();
    }
}

int createWindow(int width, int height, char* windowName, struct engineStruct* windowPtr) {

    if(!glfwInit())
        return 0;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(width, height, windowName, NULL, NULL); 
    if(!window) {
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(window);
    initGlad(glfwGetProcAddress);
    
    windowPtr->window = window;
    
    
    return 1;
}

void destroyWindow(struct engineStruct* windowPtr){
    glfwDestroyWindow(windowPtr->window);
    glfwTerminate();
    windowPtr->window = NULL;
    return;
}