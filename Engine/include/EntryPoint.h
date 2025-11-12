#pragma once

extern GEL::App* GEL::CreateApp();

int main(int argc, char* argv[]){

    auto app = GEL::CreateApp();
    app->run();
    delete app;
}