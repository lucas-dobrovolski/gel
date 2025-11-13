#include "Input.h"
#include <algorithm> // para std::fill

#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace GEL {

// ==================== VARIABLES ESTÁTICAS ====================
GLFWwindow* Input::s_Window = nullptr;
ImGuiIO* Input::s_ImGuiIO = nullptr;

// Teclado
bool Input::s_Keys[1024] = { false };
bool Input::s_KeysPressed[1024] = { false };
bool Input::s_KeysReleased[1024] = { false };

// Mouse
bool Input::s_MouseButtons[8] = { false };
bool Input::s_MouseButtonsPressed[8] = { false };
bool Input::s_MouseButtonsReleased[8] = { false };

double Input::s_MouseX = 0.0;
double Input::s_MouseY = 0.0;
double Input::s_LastMouseX = 0.0;
double Input::s_LastMouseY = 0.0;
double Input::s_DeltaX = 0.0;
double Input::s_DeltaY = 0.0;
bool Input::s_FirstMouse = true;

// ==================== INIT ====================
void Input::Init(GLFWwindow* window, ImGuiIO* imguiIO) {
    s_Window = window;
    s_ImGuiIO = imguiIO;

    // Reset arrays
    std::fill_n(s_Keys, 1024, false);
    std::fill_n(s_KeysPressed, 1024, false);
    std::fill_n(s_KeysReleased, 1024, false);
    std::fill_n(s_MouseButtons, 8, false);
    std::fill_n(s_MouseButtonsPressed, 8, false);
    std::fill_n(s_MouseButtonsReleased, 8, false);

    // Registrar callbacks
    glfwSetKeyCallback(window, Input::KeyCallback);
    glfwSetMouseButtonCallback(window, Input::MouseButtonCallback);
    glfwSetCursorPosCallback(window, Input::CursorPosCallback);
    glfwSetScrollCallback(window, Input::ScrollCallback); // AÑADIDO
    glfwSetCharCallback(window, Input::CharCallback); // AÑADIDO
}

// ==================== UPDATE ====================
void Input::Update() {
    // Reset flags de pressed/released cada frame
    std::fill_n(s_KeysPressed, 1024, false);
    std::fill_n(s_KeysReleased, 1024, false);
    std::fill_n(s_MouseButtonsPressed, 8, false);
    std::fill_n(s_MouseButtonsReleased, 8, false);

    // Calcular delta del mouse
    s_DeltaX = s_MouseX - s_LastMouseX;
    s_DeltaY = s_MouseY - s_LastMouseY;

    s_LastMouseX = s_MouseX;
    s_LastMouseY = s_MouseY;

    if (s_FirstMouse) {
        s_DeltaX = 0;
        s_DeltaY = 0;
        s_FirstMouse = false;
    }
}

// ==================== TECLADO ====================
bool Input::IsKeyDown(int key) {
    if (s_ImGuiIO && s_ImGuiIO->WantCaptureKeyboard) return false;
    return key >= 0 && key < 1024 && s_Keys[key];
}

bool Input::IsKeyPressed(int key) {
    if (s_ImGuiIO && s_ImGuiIO->WantCaptureKeyboard) return false;
    return key >= 0 && key < 1024 && s_KeysPressed[key];
}

bool Input::IsKeyReleased(int key) {
    if (s_ImGuiIO && s_ImGuiIO->WantCaptureKeyboard) return false;
    return key >= 0 && key < 1024 && s_KeysReleased[key];
}

// ==================== MOUSE ====================
bool Input::IsMouseButtonDown(int button) {
    if (s_ImGuiIO && s_ImGuiIO->WantCaptureMouse) return false;
    return button >= 0 && button < 8 && s_MouseButtons[button];
}

bool Input::IsMouseButtonPressed(int button) {
    if (s_ImGuiIO && s_ImGuiIO->WantCaptureMouse) return false;
    return button >= 0 && button < 8 && s_MouseButtonsPressed[button];
}

bool Input::IsMouseButtonReleased(int button) {
    if (s_ImGuiIO && s_ImGuiIO->WantCaptureMouse) return false;
    return button >= 0 && button < 8 && s_MouseButtonsReleased[button];
}

double Input::GetMouseX() { return s_MouseX; }
double Input::GetMouseY() { return s_MouseY; }
vec2 Input::GetMousePosition() { return { (float)s_MouseX, (float)s_MouseY }; }
double Input::GetMouseDeltaX() { return s_DeltaX; }
double Input::GetMouseDeltaY() { return s_DeltaY; }

// ==================== CALLBACKS ====================
void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // AÑADIDO: Pasar evento a ImGui
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
    
    if (key < 0 || key >= 1024) return;

    if (action == GLFW_PRESS) {
        s_Keys[key] = true;
        s_KeysPressed[key] = true;
    } else if (action == GLFW_RELEASE) {
        s_Keys[key] = false;
        s_KeysReleased[key] = true;
    }
}

void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    // AÑADIDO: Pasar evento a ImGui
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
    
    if (button < 0 || button >= 8) return;

    if (action == GLFW_PRESS) {
        s_MouseButtons[button] = true;
        s_MouseButtonsPressed[button] = true;
    } else if (action == GLFW_RELEASE) {
        s_MouseButtons[button] = false;
        s_MouseButtonsReleased[button] = true;
    }
}

void Input::CursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    // AÑADIDO: Pasar evento a ImGui
    ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);
    
    s_MouseX = xpos;
    s_MouseY = ypos;
}

// AÑADIDOS: Nuevos callbacks necesarios para ImGui
void Input::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
}

void Input::CharCallback(GLFWwindow* window, unsigned int c) {
    ImGui_ImplGlfw_CharCallback(window, c);
}

} // namespace GEL