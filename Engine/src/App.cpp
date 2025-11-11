#include "App.h"
#include "Utils.h"


namespace GEL{
    App::App()
    {
        glfw = new GLFWContext();
        window = new Window(1280, 720, "GEL Engine");
    }
    
    App::~App()
    {
        delete window;
        delete glfw;
    }

    void App::run()
    {

        LOG_INFO("Glorious Engine by Lucas running.");

        while (!window->shouldClose()) {


        window->clear({0.07f, 0.07f, 0.1f});
        window->swapBuffers();
        window->pollEvents();
    }
    }
}
