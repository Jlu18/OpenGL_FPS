#pragma once

#include "State/BaseState.h"

class GameState: public BaseState {
public:
	virtual void Init();
	virtual void CleanUp();
	virtual void Pause();
	virtual void Resume();

	virtual void HandleEvents(SDL_Event* Event);
	virtual void Update();
	virtual void Draw();
private:
	float xrel,yrel;
};