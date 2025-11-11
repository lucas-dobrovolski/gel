#pragma once

#include "Window.h"
#include "GLFWContext.h"

namespace GEL {

    class App{
        public:

        GLFWContext* glfw;
        Window* window;

        App();
        ~App();
        void run();
    };

    // a ser definido en cliente
    App* CreateApp();
}