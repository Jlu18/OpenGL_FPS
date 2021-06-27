#include "Camera.h"

#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include <cmath>

Camera::Camera(){
	pos	  = glm::vec3(0.f, 0.f,  5.f);
	up	  = glm::vec3(0.f, 1.f,  0.f);
	front = glm::vec3(0.f, 0.f, -1.f);
	right = glm::vec3(1.f, 0.f,  0.f);

	pitch = 0;
	yaw = 0; 
	roll = 0;

	move_speed = 5.f;
	look_speed = 0.05f;

	dir[0] = false;
	dir[1] = false;
	dir[2] = false;
	dir[3] = false;
}

void Camera::ToggleMove(Direction direction,bool toggle) {
	unsigned int d = static_cast<unsigned int>(direction);
	dir[d] = toggle;
}

void Camera::Move(float deltaTime) {
	float d_speed = move_speed * deltaTime;
	glm::vec3 facing(0.f,0.f,0.f);
	if (dir[0]) {
		facing += front;
	}
	if (dir[1]) {
		facing -= front;
	}
	if (dir[2]) {
		facing += right;
	}
	if (dir[3]) {
		facing -= right;
	}

	pos += facing * d_speed;
}

void Camera::Rotate(float x, float y, float z) {
	yaw = x;
	pitch = y;
	roll = z;
	UpdateRotation();
}


void Camera::Rotate(float xoffset, float yoffset, bool constrain = true) {
	//glm::vec2 m_dir = glm::normalize(glm::vec2(xoffset, yoffset));
	///m_dir *= look_speed;
	yaw += xoffset*look_speed;
	pitch -= yoffset*look_speed;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrain)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}
	UpdateRotation();
}

void Camera::UpdateRotation() {
	// calculate the new Front vector
	glm::vec3 new_front;
	new_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	new_front.y = sin(glm::radians(pitch));
	new_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(new_front);
	// also re-calculate the Right and Up vector
	right = glm::normalize(glm::cross(front, glm::vec3(0.f, 1.f, 0.f)));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up = glm::normalize(glm::cross(right, front));
}