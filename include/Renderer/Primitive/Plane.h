#pragma once
#include <glm/vec3.hpp>

class Plane {
public:
	Plane(const glm::vec3& origin, const glm::vec3& normal);
	Plane(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3);
	bool isFrontFacingTo(const glm::vec3& direction) const;
	float signedDistanceTo(const glm::vec3& point) const;

	//equation that passes through plane
	float equation[4];
	//"origin" of the plane it can be  any point inside the plane
	glm::vec3 origin;
	//normal of the plane
	glm::vec3 normal;
};

