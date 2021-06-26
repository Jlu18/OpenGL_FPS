#ifndef COMPONENT_H
#define COMPONENT_H

#include <glm/vec3.hpp>


/*
	Component for the All Entity
*/
struct TransformComponent {
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;
};

enum Tag { ENTITY,CAMERA, PLAYER };

struct TagComponent {
	Tag tag;
};

#endif
