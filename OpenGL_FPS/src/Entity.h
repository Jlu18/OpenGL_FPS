#pragma once

#include <glm/vec3.hpp>
#include "Shader.h"
#include "Texture2D.h"

class Entity {
public:
	Entity() :position(0.f), rotation(0.f), scale(1.f), texture(nullptr), name("entity"){};

//Setter
	void SetPosition(glm::vec3 new_pos) { position = new_pos; };
	void Translate(glm::vec3 dt) { position += dt; };
	void SetRotation(glm::vec3 new_rot) { rotation = new_rot; };
	void SetScale(glm::vec3 new_scal) { scale = new_scal; };

	void SetName(std::string name) { this->name = name; };
	void SetTexture(Texture2D* texture) { this->texture = texture; };

//Getter
	glm::vec3 GetPosition() { return position; };
	glm::vec3 GetRotation() { return rotation; };
	glm::vec3 GetScale()    { return scale;    };
	glm::mat4 GetTransformMatrix();

	std::string GetName() { return name; };
	Texture2D* GetTexture() { return texture; };

protected:
//General
	std::string name;
//transformation of entity
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

//temporary
	Texture2D* texture;
};	