#include <gel.h>

class Play : public GEL::App
{
    public:
    Play()
    {
        
    }
    ~Play()
    {

    }
};

GEL::App* GEL::CreateApp(){
    return new Play();
}