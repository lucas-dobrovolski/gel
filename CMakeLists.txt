cmake_minimum_required(VERSION 3.16)
project(GelProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(IMGUI_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/external/imgui/imgui.cpp    
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/external/imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/external/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/external/imgui/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/external/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/external/imgui/backends/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/external/imgui/backends/imgui_impl_opengl3.cpp
)


# --- Dependencias de bajo nivel ---
find_package(OpenGL REQUIRED)

find_package(glfw3 REQUIRED)



# --- Motor (Engine) ---
file(GLOB_RECURSE ENGINE_SOURCES
Engine/src/*.cpp
Engine/external/glad/src/glad.c
${IMGUI_SOURCES} 
)

add_library(gel SHARED ${ENGINE_SOURCES}
)

target_link_libraries(gel PRIVATE glfw OpenGL::GL)

target_include_directories(gel PUBLIC
    Engine/
    Engine/include
    Engine/external/glad/include
    Engine/external/imgui
 
)

target_compile_definitions(gel PRIVATE GEL_BUILD_DLL)
target_compile_definitions(gel PUBLIC GEL_DLL)

# --- Ejecutable principal ---
file(GLOB_RECURSE APP_SOURCES
    Play/*.cpp
)

add_executable(Play ${APP_SOURCES})
target_link_libraries(Play PRIVATE gel)

# --- Segundo ejecutable (Editor) ---
file(GLOB_RECURSE EDITOR_SOURCES
    Editor/*.cpp
)

add_executable(Editor ${EDITOR_SOURCES})
target_link_libraries(Editor PRIVATE gel)

# --- Opcional: salida más limpia ---
set_target_properties(Play Editor gel PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
