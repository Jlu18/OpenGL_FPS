#pragma once

#include <memory>

#include "StateBase.h"
#include "Entity.h"
#include "Player.h"

class StateGame : public StateBase {
public:
	virtual void Init();
	virtual void CleanUp();
	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(SDL_Event* Event);
	void KeyUp(SDL_Scancode code);
	void KeyDown(SDL_Scancode code);
	virtual void Update();
	virtual void Draw();

private:
	std::unique_ptr<Player> player;
	std::vector<std::shared_ptr<Entity>> entities;
	std::vector<std::shared_ptr<Collidable>> collidables;

	float xrel,yrel;
};