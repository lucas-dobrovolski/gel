#include "UI.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

namespace GEL {

// ----------------------------
// Variables estáticas de UI
// ----------------------------

// ----------------------------
// UI base (genérica)
// ----------------------------
void UI::Init(Window& window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO& io = ImGui::GetIO();

    // io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; //para ventanas flotantes
    
    ImGui_ImplGlfw_InitForOpenGL(window.GetGLFWwindow(), true);
    ImGui_ImplOpenGL3_Init("#version 330");
    
}

void UI::Shutdown() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UI::BeginFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void UI::EndFrame() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    /* Esto permite que las ventanas de ImGui se arrastren FUERA de tu ventana principal
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        GLFWwindow* backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();        // Actualiza ventanas flotantes
        ImGui::RenderPlatformWindowsDefault(); // Renderiza ventanas flotantes
        glfwMakeContextCurrent(backup_current_context); // Restaura contexto
    }
    */
}

// ----------------------------
// EditorUI
// ----------------------------
void EditorUI::Draw(Renderer& renderer) {

    //ImGui::DockSpaceOverViewport(); si se activa el docker

    ImGui::Begin("Renderer");
    ImGui::Text("Color de fondo (ClearColor)");
    
    static float color[3] = {0.07f, 0.07f, 0.1f};

    if (ImGui::ColorEdit3("Clear Color", color)) {
        renderer.SetClearColor({color[0], color[1], color[2]});}
    ImGui::End();
    
    ImGui::Begin("tet");
    ImGui::Text("Ctext");
    ImGui::End();
}

// ----------------------------
// PlayUI
// ----------------------------
void PlayUI::Draw() {
    


    ImGui::Begin("Play");
    ImGui::Text("Play Mode");
    ImGui::End();


}

} // namespace GEL
