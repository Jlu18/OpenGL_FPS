#pragma once
#include "Entity.h"

//base class for all the Player/NPC in the scene
class Character : public Entity {

public:
	Character();

//Movement
	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
//Look

protected:
	//direction character is looking at
	glm::vec3 front;

	float speed_forward = 0.05f;
	float speed_backward = 0.05f;
	float speed_sideways = 0.05f;
};