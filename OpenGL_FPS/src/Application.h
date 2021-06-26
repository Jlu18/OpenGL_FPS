#ifndef APPLICATION_H
#define APPLICATION_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <vector>

class Application {
private:
    bool running;
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_GLContext   context;
    //std::vector<StateBase> m_state
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