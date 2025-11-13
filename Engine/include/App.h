#pragma once

#include "Window.h"
#include "GLFWContext.h"
#include "Renderer.h"

namespace GEL {

    class App{
        public:

        GLFWContext* glfw;
        Window* window;
        Renderer* renderer;

        App();
        virtual ~App();

        void run();
        virtual void onInit();
        virtual void onUpdate();
        virtual void onRender();
        virtual void onShutdown();
    };

    // a ser definido en cliente
    App* CreateApp();
}