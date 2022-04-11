#include "BaseState.h"

void BaseState::SetKeyPress(uint32_t code, bool pressed)
{
	if (code < 286) {
		keypress[code] = pressed;
	}
}

void BaseState::SetMousePress(uint8_t code, bool pressed) {
	if (code < 6) {
		mousepress[code] = pressed;
	}
}
