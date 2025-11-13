#include "gel.h"

class Editor : public GEL::App
{
    GEL::EditorUI editorUI;

    public:

    Editor()
    {LOG_INFO("Running Editor");}
    ~Editor()
    {    }




    void onInit() override {
        GEL::App::onInit();
    }



    void onUpdate() override {

        GEL::Input::Update();

        if (GEL::Input::IsKeyDown(GLFW_KEY_BACKSPACE)) {
            renderer->SetClearColor({0.0f, 0.9f, 0.0f}); // verde
        } else {
            renderer->SetClearColor({0.07f, 0.07f, 0.1f}); // azul oscuro original
        }

    }

    void onRender() override {
        renderer->BeginFrame(*window);  

        //scene->Render();     

        GEL::UI::BeginFrame();          
        editorUI.Draw();              
        GEL::UI::EndFrame();       

        renderer->EndFrame(*window); 
    }

    void onShutdown() override {
        GEL::App::onShutdown();
    }
};

GEL::App* GEL::CreateApp(){
    return new Editor();
}