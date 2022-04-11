#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "ECS/Component/Transform.h"#pragma once

#include <memory>
#include <vector>

#include "Core/Components/Collidable.h"

namespace Ray {
	//Ray check - line vs AABBs
	Collidable* CheckFirstObjectHit(glm::vec3 origin, glm::vec3 direction, std::vector<std::shared_ptr<Collidable>> entities);
	//Sweep n Prune Alg. AABB vs AABBs
	std::vector<Collidable*> CheckOverLapObjects(Character* entity, std::vector<Collidable*>objects);
	
	void CheckCollision(Character* entity, std::vector<Collidable*>objects);
}#pragma once

#include <memory>
#include <vector>

#include "Core/Components/Collidable.h"

namespace Ray {
	//Ray check - line vs AABBs
	Collidable* CheckFirstObjectHit(glm::vec3 origin, glm::vec3 direction, std::vector<std::shared_ptr<Collidable>> entities);
	//Sweep n Prune Alg. AABB vs AABBs
	std::vector<Collidable*> CheckOverLapObjects(Character* entity, std::vector<Collidable*>objects);
	
	void CheckCollision(Character* entity, std::vector<Collidable*>objects);
}

//Based from https://learnopengl.com 
//https://learnopengl.com/code_viewer_gh.php?code=includes/learnopengl/camera.h

struct Camera {
	glm::mat4 projMatrix = glm::mat4{1.0f};
	glm::mat4 viewMatrix = glm::mat4{1.0f};

	float fov = 120.f;
	float width = 640.f;
	float height = 480.f;

	glm::vec3 front = { 0.0f, 0.0f, 1.0f };
	glm::vec3 up = { 0.0f, 1.0f, 0.0f };

	Camera() = default;
	Camera(float fov, float width, float height) {
		this->fov = fov;
		this->width = width;
		this->height = height;
		UpdateProj();
	};
	void UpdateProj() {
		projMatrix = glm::perspective(glm::radians(fov), width/height, 0.1f, 100.f);
	}
	glm::mat4 GetViewProjMatrix() const { return projMatrix * viewMatrix; };
	
	//Let's see if it's good idea to be part of component or to deal in separate place
	// 
	void UpdateView(const Transform &transform) {
		viewMatrix = glm::lookAt(transform.position, transform.position + front, up);
	}
};