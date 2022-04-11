#include "Application.h"

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


#include <string>
#include <iostream>

#include "State/StateManager.h"


Application::Application() : running(false),focus(true), window(NULL), context(NULL) {
    lastTime = currentTime = 0;
};

bool Application::OnInit() {
    std::cout << "Initializing window" << std::endl;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    //Use OpenGL 3.1 core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cout << "Error at window init: " << SDL_GetError() << std::endl;
        return false;
    }

    ////get surface
    //surface = SDL_GetWindowSurface(window);
    //get gl context
    context = SDL_GL_CreateContext(window);
    if (context == NULL)
    {
        std::cout << "Error at context init: " << SDL_GetError() << std::endl;
        return false;
    }

    /* Initialize GLEW */
    glewExperimental = true;
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cout << "Error at glew init: " << glewGetErrorString(err) << std::endl;
        return false;
    }

    //Use Vsync
    if (SDL_GL_SetSwapInterval(1) < 0)
    {
        std::cout << "Warning: Unable to set VSync! SDL Error: " <<  SDL_GetError() << std::endl;
    }

    //SDL_SetRelativeMouseMode((SDL_bool)focus);

    StateManager::Init();

    return true;
}

void Application::OnEvent(SDL_Event* e) 
{
    StateManager::CurrentState->HandleEvents(e);
}

void Application::OnLoop()
{
    StateManager::CurrentState->Update();
}

void Application::OnRender()
{
    StateManager::CurrentState->Draw();
}

void Application::OnCleanUp()
{
    StateManager::CurrentState->CleanUp();

    SDL_DestroyWindow(window);
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int Application::OnExecute() {
    //Initalized the Game
    if (!OnInit()) {
        return -1;
    }
    //Set the Game Loop to true
    running = true;

    //Print out the GL and Renderer Version
    std::cout << "Status: Using OpenGL " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Status: Using Renderer " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
    
    /* Tell GL to only draw onto a pixel if the shape is closer to the viewer */
    //glDepthFunc(GL_LESS);    // Depth-testing interprets a smaller value as "closer"

    std::cout << "Start Game Loop" << std::endl;
    SDL_Event Event;
    //int countedFrames = 0;
    while (running) {
        while (SDL_PollEvent(&Event)) {
            if (Event.type == SDL_QUIT) {
                running = false;
                break;
            }
            else if (Event.type == SDL_KEYDOWN && Event.key.keysym.sym == SDL_KeyCode::SDLK_ESCAPE) {
                focus = !focus;
                SDL_SetRelativeMouseMode((SDL_bool)focus);
            }
            OnEvent(&Event);
        }

        //float fps = countedFrames / deltaTime();
        //if (fps > 2000000) {
        //    fps = 0;
        //}
        //SDL_SetWindowTitle(window,std::to_string(fps).c_str());

        //Update
        OnLoop();
        //Render
        OnRender();
        //Place GL Context to SDL Window Updat the screen
        SDL_GL_SwapWindow(window);

        //++countedFrames;
    }
    std::cout << "Ending game loop" << std::endl;
    OnCleanUp();
   
    return 0;
}

int main(void) {
    return Application().OnExecute();
}  