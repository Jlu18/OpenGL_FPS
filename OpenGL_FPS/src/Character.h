#pragma once
#include <memory>
#include "Collidable.h"

//base class for all the Player/NPC in the scene
class Character : public Collidable {

public:
	Character();

//Movement
	void SetVelocity(glm::vec3 vel) { velocity = vel; };
	void Move(); 
//Look
	std::shared_ptr<Collidable> CheckObjectLookingAt(std::vector<std::shared_ptr<Collidable>> entities);
protected:
	//direction character is looking at
	glm::vec3 front;
	glm::vec3 up;

//collision
	glm::vec3 eclipse; //horizontal, vertical and diagonal radius of the eclipse
	glm::vec3 velocity;

	float speed = 0.1f;
};