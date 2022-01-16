#pragma once

#include <memory>
#include <vector>

#include "Core/Components/Collidable.h"

namespace Ray {
	//Ray check - line vs AABBs
	Collidable* CheckFirstObjectHit(glm::vec3 origin, glm::vec3 direction, std::vector<std::shared_ptr<Collidable>> entities);
	//Sweep n Prune Alg. AABB vs AABBs
	std::vector<Collidable*> CheckOverLapObjects(Character* entity, std::vector<Collidable*>objects);
	
	void CheckCollision(Character* entity, std::vector<Collidable*>objects);
}