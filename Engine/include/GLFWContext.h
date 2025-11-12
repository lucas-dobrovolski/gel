
#pragma once

#include <GLFW/glfw3.h>
#include "Utils.h"

class GLFWContext {
public:
    GLFWContext() {
        if (!glfwInit()) {
            LOG_ERROR("No se pudo inicializar GLFW");
        } 
    }

    ~GLFWContext() {
        glfwTerminate();
    }

};
