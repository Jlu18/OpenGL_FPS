#ifndef ENTITY_H
#define ENTITY_H

#include <entt/entt.hpp>

#include "State/BaseState.h"

/*
	Entity that is for all the entity exist in the scene (ie. camera, player, etc.)
*/
class Entity {
public:
	Entity() = default;
	Entity(entt::entity handle, BaseState *scene);
	Entity(const Entity & other) = default;

	template <typename T, typename... Args>
	void AddComponent(Args&&... args);
	
	template <typename T>
	T& GetComponent();
	
	template <typename T>
	bool HasComponent();

	template <typename T>
	void RemoveComponent();

	~Entity();
};

#endif