#pragma once

extern GEL::Application* GEL::CreateApplication();

int main(int argc, char* argv[]){

    auto app = GEL::CreateApplication();
    app->run();
    delete app;
}