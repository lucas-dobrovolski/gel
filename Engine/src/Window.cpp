#include "Window.h"
#include "Utils.h"

namespace GEL {

Window::Window(int w, int h, const std::string& t, bool vsync)
    : width(w), height(h), title(t), vsyncEnabled(vsync)
{
    // Crear la ventana GLFW
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!window) {
        LOG_ERROR("No se pudo crear la ventana GLFW");
        glfwTerminate();
        return;
    }


    glfwMakeContextCurrent(window);
    setVSync(vsyncEnabled);
}

Window::~Window()
{
    glfwDestroyWindow(window);
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(window);
}

void Window::swapBuffers()
{
    glfwSwapBuffers(window);
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::clear(vec3 color)
{
    glClearColor(color.x1, color.x2, color.x3, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::setVSync(bool enabled)
{
    vsyncEnabled = enabled;
    glfwSwapInterval(vsyncEnabled ? 1 : 0);
}

GLFWwindow* Window::GetGLFWwindow() const {
    return window;
}
}
