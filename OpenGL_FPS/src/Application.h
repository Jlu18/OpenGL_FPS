#ifndef APPLICATION_H
#define APPLICATION_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>

#include "Camera.h"

#include "StateManager.h"
#include "ResourceManager.h"
#include "Renderer.h"

class Application {
private:
    bool running;                   //game loop
    bool focus;
    SDL_Window* window;             //windows to create
    SDL_GLContext   context;        //info to draw it on
    //SDL_Surface* surface;         //use for area of graphical memory

    //find the time it last in seconds 
    Uint32 lastTime, currentTime;
    float deltaTime() {
        currentTime = SDL_GetTicks();
        Uint32 re = currentTime - lastTime;
        lastTime = currentTime;
        return static_cast<float>(re)/1000;
    }

public:
    Application();
    int OnExecute();

    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void OnCleanUp();
};

#endif