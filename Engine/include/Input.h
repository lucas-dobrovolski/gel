#pragma once
#include <GLFW/glfw3.h>
#include "Utils.h"
#include "imgui.h"

namespace GEL {

class Input {
public:

    static void Init(GLFWwindow* window, ImGuiIO* imguiIO = nullptr);

    
    static void Update();

    // ================= TECLAS =================
    static bool IsKeyDown(int key);         // presionada actualmente
    static bool IsKeyPressed(int key);      // primer frame que se presiona
    static bool IsKeyReleased(int key);     // primer frame que se suelta

    // ================= MOUSE =================
    static bool IsMouseButtonDown(int button);
    static bool IsMouseButtonPressed(int button);
    static bool IsMouseButtonReleased(int button);
    static double GetMouseX();
    static double GetMouseY();
    static vec2 GetMousePosition();
    static double GetMouseDeltaX();
    static double GetMouseDeltaY();

    // ================= CALLBACKS GLFW =================
    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
    static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    static void CharCallback(GLFWwindow* window, unsigned int c);
private:
    static GLFWwindow* s_Window;
    static ImGuiIO* s_ImGuiIO;

    // Teclado
    static bool s_Keys[1024];
    static bool s_KeysPressed[1024];
    static bool s_KeysReleased[1024];

    // Mouse
    static bool s_MouseButtons[8];
    static bool s_MouseButtonsPressed[8];
    static bool s_MouseButtonsReleased[8];

    static double s_MouseX, s_MouseY;
    static double s_LastMouseX, s_LastMouseY;
    static double s_DeltaX, s_DeltaY;
    static bool s_FirstMouse;
};

}
