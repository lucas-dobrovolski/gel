cmake_minimum_required(VERSION 3.10)
project(GEL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------


# -----------------------------
add_library(gel SHARED # Biblioteca compartida (gel)
    Engine/src/Application.cpp    
)

target_include_directories(gel PUBLIC # Incluir headers de todo el motor
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine        # para gel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Engine/dep    # para headers dentro de dep/
)



add_executable(app Sandbox/SandboxApp.cpp) # Ejecutable (SandboxApp)

target_link_libraries(app PRIVATE gel) # Enlazar app con la librería

#### cosas mas especificas

set_target_properties(app PROPERTIES #decirle dónde buscar la .so/.dll en tiempo de ejecución
    BUILD_RPATH "${CMAKE_CURRENT_SOURCE_DIR}/Engine"
)

if (WIN32) # si es en windows copiar la DLL junto al ejecutable
    add_custom_command(TARGET app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:gel>
            $<TARGET_FILE_DIR:app>
    )
endif()
