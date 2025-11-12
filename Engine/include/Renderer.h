#pragma once

#include "Window.h"

namespace GEL {
    class Renderer {
    public:
        void BeginFrame(Window& window, GEL::Color3 clearColor);
        void EndFrame(Window& window);
    };
}