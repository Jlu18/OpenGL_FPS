#pragma once

#include <memory>
#include <vector>

#include "Collidable.h"
#include "Character.h"

namespace Ray {
	std::shared_ptr<Collidable> CheckFirstObjectHit(glm::vec3 origin, glm::vec3 direction, std::vector<std::shared_ptr<Collidable>> entities);
	std::vector<std::shared_ptr<Collidable>> CheckOverLapObjects(Character* entity, std::vector<std::shared_ptr<Collidable>>objects);
	void CheckCollision(Character* entity, std::vector<std::shared_ptr<Collidable>>objects);
}