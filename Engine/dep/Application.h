#pragma once

namespace GEL {

    class Application{
        public:
        Application();
        ~Application();
        void run();
    };

    // a ser definido en cliente
    Application* CreateApplication();
}