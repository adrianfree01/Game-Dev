#include <stdio.h>
#include <stdbool.h>

#include <GLFW/glfw3.h>

#include "engine.h"
#include "window.h"
#include "render.h"

void errorCallback(int errorCode, const char* desc) {
    fprintf(stderr, "GLFW Error (%d): %s\n", errorCode, desc);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    (void)window; // marking as unused
    resizeViewport(width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void windowLoop(struct engine* windowPtr){
    while(!glfwWindowShouldClose(windowPtr->window)) {
        processInput(windowPtr->window);

        renderScreen();

        glfwSwapBuffers(windowPtr->window);
        glfwPollEvents();
    }
}

int createWindow(int width, int height, char* windowName, struct engine* windowPtr) {

    glfwSetErrorCallback(errorCallback);
    
    if(!glfwInit()) {
        return 0;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(width, height, windowName, NULL, NULL); 
    if(!window) {
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    int framebufferWidth, framebufferHeight;
    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
    if(!initGlad(glfwGetProcAddress, framebufferWidth, framebufferHeight)) {
        fprintf(stderr, "Failed to initialize GLAD");
        glfwTerminate();
        return 0;
    }
    windowPtr->window = window;
    
    return 1;
}

void destroyWindow(struct engine* windowPtr){
    glfwDestroyWindow(windowPtr->window);
    glfwTerminate();
    windowPtr->window = NULL;
    return;
}