#pragma once

#include <glm/vec3.hpp>
#include "Entity.h"

struct BoundingBox { //AABB
	glm::vec3 min, max;
};

enum class Axis {x,y,z};

class Collidable : public Entity {
public:
	Collidable() { UpdateBox(); };

	BoundingBox GetBoundingBox() { return aabb; };
	void UpdateBox() {
		//TODO - Count rotation by apply rotation matrix
		aabb.min = position - scale / 2.0f; //min
		aabb.max = position + scale / 2.0f;  //max
	};
	bool Intersect(Collidable* collidable) {
		BoundingBox b1 = collidable->GetBoundingBox();
		if (aabb.max.x < b1.min.x
			|| b1.max.x < aabb.min.x
			|| aabb.max.y < b1.min.y
			|| b1.max.y < aabb.min.y
			|| aabb.max.z < b1.min.z
			|| b1.max.z < aabb.min.z)	return false;

		return true;
	};
	bool Intersect(Collidable* collidable, Axis a) {
		BoundingBox b1 = collidable-> GetBoundingBox();
		switch(a){
			case Axis::x:
				return aabb.max.x < b1.min.x || b1.max.x < aabb.min.x;
			case Axis::y:
				return aabb.max.y < b1.min.y || b1.max.y < aabb.min.y;
			case Axis::z:
				return aabb.max.z < b1.min.z || b1.max.z < aabb.min.z;
		}
		return false;
	}
private:
	BoundingBox aabb;
}; 