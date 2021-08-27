#pragma once
#include <memory>
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

	void MoveUp();
	void MoveDown();

	bool Colliding(); 
//Look

	std::shared_ptr<Entity> CheckObjectLookingAt(std::vector<std::shared_ptr<Entity>> entities);
protected:
	//direction character is looking at
	glm::vec3 front;
	glm::vec3 up;

	float speed = 0.1f;
};