#pragma once

#include <GLFW/glfw3.h>
#include "Utils.h"

namespace GEL {
    class Window {
        private:
            GLFWwindow* window;
            std::string title;
            int width, height;
            bool vsyncEnabled;

        public: 
            Window(int w, int h, const std::string& t, bool vsync = true);
            ~Window();

            GLFWwindow* getGLFWwindow() const { return window; }

            int getWidth() const { return width; }
            int getHeight() const { return height; }

            bool shouldClose() const;

            void swapBuffers();

            void pollEvents();

            void clear(vec3); 

            void setVSync(bool enabled);
            bool isVSyncEnabled() const { return vsyncEnabled; }

            GLFWwindow* GetGLFWwindow() const;
    };

}