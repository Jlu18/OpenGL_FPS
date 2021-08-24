#pragma once
#include "StateGame.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Setting.h"

void StateGame::Init()
{
//Renderer
	Renderer::Init();

	ResourceManager::LoadTexture("res/texture/bear2.png", true, "bear");
	//ResourceManager::LoadTexture("res/texture/wall.jpg", false, "wall");
	Texture2D* bear_texture = ResourceManager::GetTexture("bear");
	//Texture2D* wall_texture = ResourceManager::GetTexture("wall");
//Player
	player = std::make_unique<Player>();

	entities.push_back(std::make_shared<Entity>());
	entities[0]->SetScale({ 5.0f, 5.0f, 5.0f });
	entities[0]->SetPosition({ 0.0f,0.0f, 10.0f });
	entities[0]->SetTexture(bear_texture);
	
	entities.push_back(std::make_shared<Entity>());
	entities[1]->SetScale({ 100.0f, 1.0f, 100.0f });
	entities[1]->SetPosition({ 0.0f,-10.0f, 0.0f });

	xrel = 0.0f;
	yrel = 0.0f;

	glEnable(GL_DEPTH_TEST); //Enable depth-testing
}

void StateGame::CleanUp()
{
	Renderer::CleanUp();
	ResourceManager::Clear();
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
			xrel = (float)Event->motion.xrel; 
			yrel = (float)Event->motion.yrel;
		}
		break;
	}
}

void StateGame::Update()
{
	if (keypress[Setting::FORWARD]) {
		//std::cout << "W\n";
		player->MoveForward();
	}
	if (keypress[Setting::BACKWARD]) {
		//std::cout << "S\n";
		player->MoveBackward();
	}
	if (keypress[Setting::LEFT]) {
		//std::cout << "A\n";
		player->MoveLeft();
	}
	if (keypress[Setting::RIGHT]) {
		//std::cout << "D\n";
		player->MoveRight();
	}
	if (xrel != 0.0f || yrel != 0.0f) {
		player->OnMouseMove(xrel, yrel);
		xrel = 0.0f;
		yrel = 0.0f;
	}
	player->Update();
	entities[0]->SetRotation(entities[0]->GetRotation() + glm::vec3{0.0f, 1.0f, 0.0f});
}

void StateGame::Draw()
{
	GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

	Renderer::RenderTexture(entities,player->GetViewProjMatrix());
}
