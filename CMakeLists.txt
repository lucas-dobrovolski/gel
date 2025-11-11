cmake_minimum_required(VERSION 3.10)
project(GEL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Dependencias
# -----------------------------
find_package(OpenGL REQUIRED)

# Intentar encontrar GLFW
find_package(glfw3 QUIET)
if (NOT glfw3_FOUND)
    message(STATUS "glfw3 not found via find_package, trying pkg-config...")
    find_package(PkgConfig REQUIRED)
    pkg_search_module(GLFW REQUIRED glfw3)
endif()

# -----------------------------
# Biblioteca del motor
# -----------------------------
add_library(gel SHARED
    Engine/src/App.cpp  
    Engine/src/Window.cpp  
)

target_include_directories(gel PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/dep
)

# Enlazar dependencias al motor
if (TARGET glfw)
    target_link_libraries(gel PRIVATE glfw OpenGL::GL)
elseif (GLFW_FOUND)
    target_link_libraries(gel PRIVATE ${GLFW_LIBRARIES} OpenGL::GL)
else()
    target_link_libraries(gel PRIVATE glfw3 OpenGL::GL)
endif()

# -----------------------------
# Ejecutable de prueba (Play)
# -----------------------------
add_executable(app Play/Play.cpp)

target_link_libraries(app PRIVATE gel)

set_target_properties(app PROPERTIES
    BUILD_RPATH "${CMAKE_CURRENT_SOURCE_DIR}/Engine"
)

if (WIN32)
    add_custom_command(TARGET app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:gel>
            $<TARGET_FILE_DIR:app>
    )
endif()
