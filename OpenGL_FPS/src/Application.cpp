#include "Application.h"

#include <GL/glew.h>
#include <SDL_opengl.h>

#include <string>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include "Box.h"
#include "Util.h"

Application::Application() : running(false), window(NULL), surface(NULL), context(NULL) {
    lastTime = currentTime = 0;
    keydown = false;
    press[0] = false;
    press[1] = false;
    press[2] = false;
    press[3] = false;
};

bool Application::OnInit() {
    std::cout << "Initializing window" << std::endl;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    //Use OpenGL 3.1 core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
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

    return true;
}

void Application::OnEvent(SDL_Event* event) {

    switch(event->type){
        case SDL_QUIT:
            running = false;
            return;
        case SDL_KEYDOWN:
            if (!event->key.repeat) {
                switch (event->key.keysym.sym)
                {
                case SDLK_w:
                case SDLK_UP:       press[0] = true; break;
                case SDLK_s:
                case SDLK_DOWN:     press[1] = true; break;
                case SDLK_a:
                case SDLK_LEFT:     press[2] = true; break;
                case SDLK_d:
                case SDLK_RIGHT:    press[3] = true; break;
                }
            }
            break;
        case SDL_KEYUP:
            if (!event->key.repeat) {
                switch (event->key.keysym.sym)
                {
                case SDLK_w:    
                case SDLK_UP:       press[0] = false; break;
                case SDLK_s:   
                case SDLK_DOWN:     press[1] = false; break;
                case SDLK_a:
                case SDLK_LEFT:     press[2] = false; break;
                case SDLK_d:
                case SDLK_RIGHT:    press[3] = false; break;
                }
            }
    }
}

void Application::OnLoop() {
}

void Application::OnRender() {
    GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Application::OnCleanUp(){
 
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

    glViewport(0, 0, 640, 480);
    /* Tell GL to only draw onto a pixel if the shape is closer to the viewer */
    //glEnable(GL_DEPTH_TEST); //Enable depth-testing
    //glDepthFunc(GL_LESS); // Depth-testing interprets a smaller value as "closer"
    Shader basic_shader = Shader("./res/shader/Basic.shader");
    Box b = Box(&basic_shader);
    Box b2 = Box(&basic_shader);
    //Square s = Square(&basic_shader);

    std::cout << "Start Game Loop" << std::endl;

    glm::mat4 proj_matrix = glm::perspective(glm::radians(60.f),640.f/480.f,0.1f,100.f);
    
    float angle = 0;
    //SDL Event 
    SDL_Event Event;
    
    b2.move(0.5, 0, -0.5);

    basic_shader.Bind();
    while (running) {
        while (SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
        //OnLoop();
        angle += 0.5;
        b.rotate(angle, 0.5f, 1.f, 0.f);
        b2.rotate(angle, 0.5f, 1.f, 0.f);
        if (angle >= 360) angle = 0;

        float d = deltaTime();
        if (press[0]) {
            cam.Move(Direction::FORWARD, d);
        }
        if (press[1]) {
            cam.Move(Direction::BACKWARD, d);
        }
        if (press[2]) {
            cam.Move(Direction::RIGHT, d);
        }
        if (press[3]) {
            cam.Move(Direction::LEFT, d);
        }


        //Render
        OnRender();

        b.BindAll();
        basic_shader.SetUniform4f("u_Color", 1.0f, 0.f, 0.f, 1.0f);
        b.Draw(proj_matrix * cam.GetViewMatrix());

        b2.BindAll();
        basic_shader.SetUniform4f("u_Color", 0.f, 1.f, 0.f, 1.0f);
        b2.Draw(proj_matrix * cam.GetViewMatrix());

        //Place GL Context to SDL Window Updat the screen
        SDL_GL_SwapWindow(window);
    }
    std::cout << "Ending game loop" << std::endl;
    OnCleanUp();
   
    return 0;
}

int main(void) {
    return Application().OnExecute();
}  