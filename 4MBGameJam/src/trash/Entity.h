#ifndef ENTITY_H
#define ENTITY_H

#include <entt.hpp>

#include "Component.h"
#include "Scene.h"

/*
	Entity that is for all the entity exist in the scene (ie. camera, player, etc.)
*/
class Entity {
public:
	Entity() = default;
	Entity(entt::entity handle, Scene* scene);
	~Entity();
};

#endif