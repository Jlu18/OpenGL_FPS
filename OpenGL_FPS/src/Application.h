#ifndef APPLICATION_H
#define APPLICATION_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <vector>

#include "Camera.h"

class Application {
private:
    bool running;
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_GLContext   context;
    //std::vector<StateBase> m_state

    Camera cam; //temp;
    bool keydown;

    bool press[4]; //0 = forward; 1=backward; 2=right; 3=left;

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