#pragma once

#include "Camera.h"
#include "Transform.h"


struct Player {

	glm::vec3 velocity = {};
	float speed = 0.2f;
	void Move(Transform& transform,const Camera& cam) {
		transform.Translate(velocity.z * cam.front * speed);
		transform.Translate(velocity.x * glm::cross(cam.front, cam.up) * speed);
		transform.Translate(velocity.y * glm::vec3(0.0f, 1.0f, 0.0f) * speed);
	}

	/*
		Deal with the rotation of transform and camera of mouse movement
		?: Is it appropriate to put in this component?
			I think it's probably more appropriate to put in Camera component instead
	*/
	void OnMouseMove(Transform& transform, Camera& cam, glm::vec2 m_rel) {
		//Update the rotation in character.h
		//xrel is apply to yaw because xrel is horizontal movement which rotates character in y-axis(yaw)
		//yrel is apply to pitch because yrel is vertical movement which rotates character in x-axis(pitch)
		transform.rotation.x -= m_rel.y; //pitch
		transform.rotation.y += m_rel.x; //yaw

		//constrain
		if (transform.rotation.x > 89.0f)
			transform.rotation.x = 89.0f;
		if (transform.rotation.x < -89.0f)
			transform.rotation.x = -89.0f;;

		// calculate the new Front vector
		glm::vec3 new_front{ 0.0f };
		new_front.x = cos(glm::radians(transform.rotation.y)) * cos(glm::radians(transform.rotation.x));
		new_front.y = sin(glm::radians(transform.rotation.x));
		new_front.z = sin(glm::radians(transform.rotation.y)) * cos(glm::radians(transform.rotation.x));
		cam.front = glm::normalize(new_front);

		// normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		glm::vec3 right = glm::normalize(glm::cross(cam.front, { 0.0f,1.0f,0.0f }));  
		cam.up = glm::normalize(glm::cross(right, cam.front));
	}
};
