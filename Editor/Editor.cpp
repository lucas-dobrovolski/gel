#include "gel.h"

class Editor : public GEL::App
{
    public:
    Editor()
    {
        LOG_INFO("Editor");
    }
    ~Editor()
    {

    }
};

GEL::App* GEL::CreateApp(){
    return new Editor();
}