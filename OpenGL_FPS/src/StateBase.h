#pragma once

#include <SDL.h>
#include <glm/vec2.hpp>

//http://gamedevgeek.com/tutorials/managing-game-states-in-c/
class StateBase {
public:
	StateBase() {};
	~StateBase() {};
	virtual void Init() = 0;
	virtual void CleanUp() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents(SDL_Event* Event) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	void SetKeyPress(uint32_t code, bool pressed = true);
	void SetMousePress(uint8_t code, bool pressed = true);

	//log the status of keypressed on each key,
	//each index represents SDK_KeyCode
	bool keypress[286] = { 0 };
	//0 - ; 1-left click; 2-scroll wheek click; 3-right click; 4-lower button; 5-upper button; 
	bool mousepress[6] = { 0 };
	glm::vec2 mousemove { 0.f };
};