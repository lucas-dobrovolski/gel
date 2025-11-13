#pragma once
#include <imgui.h>
#include "Window.h"

namespace GEL {

// ----------------------------
// UI base (genérica)
// ----------------------------
class UI {
public:
    static void Init(Window& window);
    static void Shutdown();

    static void BeginFrame();
    static void EndFrame();
};

// ----------------------------
// UI EDITOR
// ----------------------------
class EditorUI {
public:
    bool showDemo = true;
    void Draw();
};

// ----------------------------
// UI PLAY
// ----------------------------
class PlayUI {
public:
    void Draw();
};

} // namespace GEL
