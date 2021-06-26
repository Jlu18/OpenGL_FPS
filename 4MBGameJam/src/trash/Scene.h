#ifndef SCENE_H
#define SCENE_H
#include <string>

#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include <entt.hpp>

class Scene{
    entt::registry m_registry;
public:
    Scene();
    ~Scene();   
};

#endif