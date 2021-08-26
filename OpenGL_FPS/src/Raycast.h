#pragma once

#include <memory>
#include <vector>

#include "Entity.h"

namespace Ray {
	std::shared_ptr<Entity> CheckFirstObjectHit(glm::vec3 origin, glm::vec3 direction, std::vector<std::shared_ptr<Entity>> entities);
}