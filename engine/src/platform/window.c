#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "engine.h"


int createWindow(int width, int height, char* windowName) {

    if(!glfwInit())
        return 0;
    GLFWwindow* window = glfwCreateWindow(width, height, windowName, NULL, NULL);
    if(!window)
        return 0;
    
    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);


    return 1;
}