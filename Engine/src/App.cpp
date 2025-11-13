#include "App.h"
#include "Utils.h"
#include "Renderer.h"
#include "Input.h"
#include "UI.h"



namespace GEL{
    App::App()
    {
        glfw = new GLFWContext();
        window = new Window(1280, 720, "GEL Engine");
        renderer = new Renderer();
    }
    
    App::~App()
    {
        delete window;
        delete glfw;
        delete renderer;
    }




    void App::onInit(){
        
        GEL::UI::Init(*window);

        GEL::Input::Init(window->GetGLFWwindow(), &ImGui::GetIO());

        LOG_INFO("Glorious Engine by Lucas running. No type");
    }




    void GEL::App::onUpdate() {

    }




    void App::onRender() 
    {
    }

    void App::onShutdown() {
        GEL::UI::Shutdown();  
    }

    void App::run()
    {

        onInit();

        while (!window->shouldClose()) {

            onUpdate();
            onRender();
            
            window->pollEvents();
    }
    onShutdown();

    }
}
