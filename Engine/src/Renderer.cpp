#include "Renderer.h"

namespace GEL {

    vec3 clearColor = {0.07f, 0.07f, 0.1f};
    
    void Renderer::SetClearColor(const vec3& color) { clearColor = color; }

    void Renderer::BeginFrame(Window& window) {
        window.clear(clearColor);
    }

    
    void Renderer::EndFrame(Window& window) {
        window.swapBuffers();
    }

}
