#include <glad/gl.h>
#include "engine.h"
#include "render.h"
#include "window.h"

int initGlad(LoadFn glfwProcAddr, int width, int height) {
    if(!gladLoadGL(glfwProcAddr)) {
        return 0;
    }
    resizeViewport(width, height);
    return 1;
}

void resizeViewport(int width, int height) {
    glViewport(0, 0, width, height);
}

void renderScreen(void) {
    glClearColor(0.7f, 0.1f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
