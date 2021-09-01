#include "Raycast.h"
namespace Ray {
	/*
		From "An Efficientand Robust Ray-Box Intersection Algorithm"
			by Williams, et al. 2005.
	*/
	std::shared_ptr<Entity> CheckFirstObjectHit(glm::vec3 origin, glm::vec3 direction, std::vector<std::shared_ptr<Entity>> entities)
	{
		float tmin, tmax, tymin, tymax, tzmin, tzmax;
		for (unsigned int i = 0; i < entities.size(); i++) {
			if (!(entities[i]->CollisionEnabled())) continue;

			struct Box boundry = entities[i]->GetCollisionBox();

			glm::vec3 b_max = boundry.max;
			glm::vec3 b_min = boundry.min;
		
			if (direction.x >= 0) {
				tmin = (b_min.x - origin.x) / direction.x;
				tmax = (b_max.x - origin.x) / direction.x;
			}
			else {
				tmin = (b_max.x - origin.x) / direction.x;
				tmax = (b_min.x - origin.x) / direction.x;
			}

			if (direction.y >= 0) {
				tymin = (b_min.y - origin.y) / direction.y;
				tymax = (b_max.y - origin.y) / direction.y;
			}
			else {
				tymin = (b_max.y - origin.y) / direction.y;
				tymax = (b_min.y - origin.y) / direction.y;
			}

			//outside bound skip/break this iteration
			if ((tmin > tymax) || (tymin > tmax)) continue;

			if (tymin > tmin)
				tmin = tymin;

			if (tymax < tmax)
				tmax = tymax;

			if (direction.z >= 0) {
				tzmin = (b_min.z - origin.z) / direction.z;
				tzmax = (b_max.z - origin.z) / direction.z;
			}
			else {
				tzmin = (b_max.z - origin.z) / direction.z;
				tzmax = (b_min.z - origin.z) / direction.z;
			}

			//outside bound skip/break this iteration
			if ((tmin > tzmax) || (tzmin > tmax)) continue;

			//pass all the test
			return entities[i];
		}
		return nullptr;
	}
}

