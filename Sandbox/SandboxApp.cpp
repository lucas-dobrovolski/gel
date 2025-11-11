#include <gel.h>

class Sandbox : public GEL::Application
{
    public:
    Sandbox()
    {
        
    }
    ~Sandbox()
    {

    }
};

GEL::Application* GEL::CreateApplication(){
    return new Sandbox();
}