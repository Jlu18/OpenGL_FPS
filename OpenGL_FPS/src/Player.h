#pragma once

#include "Setting.h"

#include "Camera.h"


class Player : public FPCamera {
public:
	Player();
	void Update() { UpdateView(); };
	void OnMouseMove(float xrel, float yrel);
};