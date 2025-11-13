#pragma once

#include "Window.h"
#include "Utils.h"
#include "World.h"
namespace GEL {
    class Renderer {
        vec3 clearColor = {0.08f, 0.12f, 0.21f};
    
        public:
            void SetClearColor(const vec3& color);

            void BeginFrame(Window& window);

            void draw(const World& world);
            //void renderEditorOverlay(const EditorOverlay& overlay);


            void EndFrame(Window& window);
    };
}