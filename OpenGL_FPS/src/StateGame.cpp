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

	for (unsigned int i = 0; i < 10; i++) {
		entities.push_back(std::make_shared<Entity>());
		entities[i]->SetScale({ 5.0f, 5.0f, 5.0f });
		entities[i]->SetRotation({ 0.0f, 45.f, 0.f });
		entities[i]->SetPosition({ i * 10.0f - 50.0f,0.0f, 5.0f });
		entities[i]->SetTexture(bear_texture);
		entities[i]->SetName("entity" + std::to_string(i));
	}

	xrel = 0.0f;
	yrel = 0.0f;

	GLCall(glEnable(GL_DEPTH_TEST)); //Enable depth-testing
	//GLCall(glEnable(GL_CULL_FACE));
	//glCullFace(GL_FRONT);	
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
		SetKeyPress(Event->key.keysym.scancode, true);
		break;
	case SDL_KEYUP:
		SetKeyPress(Event->key.keysym.scancode, false);
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
		//if(!player->CollidingFront(entities))
			player->MoveForward();
	}
	if (keypress[Setting::BACKWARD]) {
		//std::cout << "S\n";
		//if(!player->CollidingBack(entities))
			player->MoveBackward();
	}
	if (keypress[Setting::LEFT]) {
		//std::cout << "A\n";
		//if(!player->CollidingLeft(entities))
		player->MoveLeft();
	}
	if (keypress[Setting::RIGHT]) {
		//std::cout << "D\n";
		//if(!player->CollidingRight(entities))
		player->MoveRight();
	}
	if (keypress[Setting::JUMP]) {
		//if(!player->CollidingUp(entities))
		player->MoveUp();
	}
	if (keypress[Setting::DOWN]) {
		//if(!player->CollidingDown(entities))
		player->MoveDown();
	}
	if (xrel != 0.0f || yrel != 0.0f) {
		player->OnMouseMove(xrel, yrel);
		xrel = 0.0f;
		yrel = 0.0f;
	}

	if (mousepress[1]) {
		std::shared_ptr<Entity> ray_entity = player->CheckObjectLookingAt(entities);
		if ( ray_entity != nullptr) {
			std::cout << "player hit: " << (ray_entity)->GetName() << '\n';
		}
		else {
			std::cout << "No entity hitted :(\n";
		}
	}

	//std::cout << mousepress[0] << ' ' << mousepress[1] << ' ' << mousepress[2] << ' ' << mousepress[3] << ' ' << mousepress[4] << ' ' << mousepress[5] << '\n';

	player->Update();
	//entities[0]->SetRotation(entities[0]->GetRotation() + glm::vec3{0.0f, 1.0f, 0.0f});
}

void StateGame::Draw()
{
	GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

	Renderer::RenderTexture(entities,player->GetViewProjMatrix());
}
