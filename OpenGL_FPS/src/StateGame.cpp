#pragma once
#include "StateGame.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Setting.h"

void StateGame::Init()
{
//Renderer
	Renderer::Init();

//Player
	player = std::make_unique<Player>();

	entity = std::make_unique<Entity>();
	entity->SetScale({ 5.0f, 5.0f, 5.0f });
	entity->SetPosition({ 0.0f,0.0f,5.0f });

	xrel = 0.0f;
	yrel = 0.0f;
}

void StateGame::CleanUp()
{
	Renderer::CleanUp();
}

void StateGame::Pause()
{
}

void StateGame::Resume()
{
}

void StateGame::HandleEvents(SDL_Event* Event)
{
	switch (Event->type) {
	case SDL_KEYDOWN:
		SetKeyPress(Event->key.keysym.sym, true);
		break;
	case SDL_KEYUP:
		SetKeyPress(Event->key.keysym.sym, false);
		break;
	case SDL_MOUSEBUTTONDOWN:
		SetMousePress(Event->button.button, true);
		break;
	case SDL_MOUSEBUTTONUP:
		SetMousePress(Event->button.button, false);
		break;
	case SDL_MOUSEMOTION:
		if (SDL_GetRelativeMouseMode()) {
			xrel = Event->motion.xrel; 
			yrel = Event->motion.yrel;
		}
		break;
	}
}

void StateGame::Update()
{
	if (keypress[Setting::FORWARD]) {
		player->MoveForward();
	}
	if (keypress[Setting::BACKWARD]) {
		player->MoveBackward();
	}
	if (keypress[Setting::LEFT]) {
		player->MoveLeft();
	}
	if (keypress[Setting::RIGHT]) {
		player->MoveRight();
	}
	player->CRotate(xrel, yrel);
	xrel = 0.0f;
	yrel = 0.0f;

}

void StateGame::Draw()
{
	GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT));

	Renderer::Bind();
	Renderer::Render(entity.get(),player->GetViewProjMatrix());
}
