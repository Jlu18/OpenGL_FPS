#pragma once

#include "Renderer/Primitive/Plane.h"
#include "glm/gtc/matrix_transform.hpp"

Plane::Plane(const glm::vec3& origin, const glm::vec3& normal) {
	this->normal = normal;
	this->origin = origin;
	equation[0] = normal.x;
	equation[1] = normal.y;
	equation[2] = normal.z;
	equation[3] = -(normal.x * origin.x + normal.y * origin.y
		+ normal.z * origin.z);
}

// Construct from triangle:
Plane::Plane(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3 & p3)
{
	normal = glm::cross((p2 - p1),(p3 - p1));
	normal = glm::normalize(normal);
	origin = p1;
	equation[0] = normal.x;
	equation[1] = normal.y;
	equation[2] = normal.z;
	equation[3] = -(normal.x * origin.x + normal.y * origin.y
		+ normal.z * origin.z);
}

bool Plane::isFrontFacingTo(const glm::vec3& direction) const {
	double dot = glm::dot(normal,direction);
	return (dot <= 0);
}

float Plane::signedDistanceTo(const glm::vec3& point) const {
	return glm::dot(point,normal) + equation[3];
}
