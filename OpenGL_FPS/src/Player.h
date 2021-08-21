#pragma once

#include "Setting.h"

#include "Character.h"
#include "Camera.h"


class Player : public Character, public Camera {
public:
	Player();

	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
};