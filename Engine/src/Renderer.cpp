#include "Renderer.h"

namespace GEL {

    void Renderer::BeginFrame(Window& window, GEL::Color3 clearColor) {
        window.clear(clearColor);
    }

    void Renderer::EndFrame(Window& window) {
        window.swapBuffers();
    }

}
