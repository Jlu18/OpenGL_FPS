#pragma once

#include "GameState.h"

#include "Renderer/Renderer.h"
#include "Resource/ResourceManager.h"
#include "Resource/Setting.h"
#include "Entity/Component/Components.h" 

#include <iostream>
#include <stdio.h>
#include "glm/gtx/string_cast.hpp"

void GameState::Init()
{
	Renderer::Init();

	//ResourceManager::LoadTexture("res/texture/bear2.png",true,"bear");
	// 
	//camera
	const auto entt_player = registry.create();

	Transform& transform = registry.emplace<Transform>(entt_player);
	transform.position = glm::vec3(0.0f, 0.0f, -30.0f);
	transform.scale = { 1.0f, 1.0f, 1.0f };
	transform.rotation = {0.0f, 0.0f, 0.0f };
	registry.emplace<Player>(entt_player);

	Camera& camera = registry.emplace<Camera>(entt_player);
	camera.fov = Setting::FOV;
	camera.width  = (float)Setting::WIDTH;
	camera.height = (float)Setting::HEIGHT;
	camera.UpdateProj();
	camera.UpdateView(transform);
	
	//boxes
	for (int i = 0; i < 10; i++) {
		const auto entity = registry.create();
		Renderable& renderable = registry.emplace<Renderable>(entity);
		renderable.texture = "bear";
		renderable.color = glm::vec4(1.0f-(0.2/i), 0.5f - (0.05/i), 0.5f - (0.02/i), 1.0f);
		Transform& transform = registry.emplace<Transform>(entity);
		transform.position = { i*5.f - 25.f, 0.f, -10.f };
		transform.scale = { 1.0f, 1.0f, 1.0f};
		transform.rotation = { 360.f / i, 0.0f, 0.0f };
	}

	xrel = 0.0f;
	yrel = 0.0f;
}

void GameState::CleanUp()
{
	ResourceManager::Clear();
	Renderer::CleanUp();
}

void GameState::Pause()
{
}

void GameState::Resume()
{
}

void GameState::HandleEvents(SDL_Event* Event)
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

void GameState::Update()
{
	glm::vec3 velocity{ 0.f };
	if (keypress[Setting::FORWARD]) {
		velocity.z += 1.f;
	}
	if (keypress[Setting::BACKWARD]) {
		velocity.z -= 1.f;
	}
	if (keypress[Setting::LEFT]) {
		velocity.x -= 1.f;
	}
	if (keypress[Setting::RIGHT]) {
		velocity.x += 1.f;
	}
	if (keypress[Setting::JUMP]) {
		velocity.y += 1.f;
	}
	if (keypress[Setting::DOWN]) {
		velocity.y -= 1.f;
	}

	//get with
	auto player_view = registry.view<Camera, Transform, Player>();
	//for each camera and transform
	player_view.each([&](auto &camera, auto &transform, auto& player) {
		//rotate the transformation based on player movement
		if (xrel != 0.0f || yrel != 0.0f) {
			player.OnMouseMove(transform, camera, { xrel, yrel });
			xrel = 0.0f;
			yrel = 0.0f;
		}
		////translate the position of camera
		player.velocity = velocity;		//Set Velocity
		player.Move(transform, camera);	//Update Velocity

		////Update camera view matrix
		camera.UpdateView(transform);			   //Update View Matrix
		std::cout << "\r" << glm::to_string(transform.position) << std::flush;
	});

	if (mousepress[1]) {
		//auto objects = registry.view<Transform>();
		//std::shared_ptr<Object> ray_entity = player->CheckObjectLookingAt(map);
		//if ( ray_entity != nullptr) {
		//	std::cout << "player hit: " << (ray_entity)->GetName() << '\n';
		//}
		//else {
		//	std::cout << "No entity hitted :(\n";
		//}
	}
	//entities[0]->SetRotation(entities[0]->GetRotation() + glm::vec3{0.0f, 1.0f, 0.0f});

	//auto view_drawables = registry.view<Renderable, Transform>();
	//for (auto entt_drawable : view_drawables) {
	//	auto &transform = view_drawables.get<Transform>(entt_drawable);
	//	transform.rotation = transform.rotation + glm::vec3{ 1.0f, 0.0f, 0.0f };
	//}
}

void GameState::Draw()
{
	Renderer::Clear(glm::vec3(0.7f,0.7f,0.7f));
	
	auto entt_camera = registry.view<Camera>()[0];
	Renderer::PreRender(registry.get<Camera>(entt_camera));

	//Renderer::Render
	auto view_drawables = registry.view<Renderable,Transform>();
	for (auto entt_drawable : view_drawables) {
		auto [renderable, transform] = view_drawables.get(entt_drawable); 
		Renderer::Render(transform, renderable);
	}

	Renderer::PostRender();
}
