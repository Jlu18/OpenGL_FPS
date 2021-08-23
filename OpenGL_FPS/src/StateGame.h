#pragma once

#include <memory>

#include "StateBase.h"
#include "Player.h"
#include "Entity.h"

class StateGame : public StateBase {
public:
	virtual void Init();
	virtual void CleanUp();
	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(SDL_Event* Event);
	virtual void Update();
	virtual void Draw();

private:
	std::unique_ptr<Player> player;
	std::vector<std::shared_ptr<Entity>> entities;

	float xrel,yrel;
};