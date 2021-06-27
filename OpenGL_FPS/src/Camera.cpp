#include "Camera.h"

Camera::Camera(){
	pos	  = glm::vec3(0.f,0.f,5.f);
	up	  = glm::vec3(0.f, 1.f,  0.f);
	front = glm::vec3(0.f, 0.f, -1.f);
	right = glm::vec3(1.f, 0.f,  0.f);

	pitch = 0;
	yaw = 0; 
	roll = 0;

	move_speed = 5.f;
	look_speed = 0.1f;

	fov = 60;
	aspectRatio = 640.f / 480.f;
}

void Camera::UpdateRotation() {
	// calculate the new Front vector
	glm::vec3 new_front;
	new_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	new_front.y = sin(glm::radians(pitch));
	new_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(front);
	// also re-calculate the Right and Up vector
	right = glm::normalize(glm::cross(front, glm::vec3(0.f,1.f,0.f)));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up = glm::normalize(glm::cross(right, front));
}

void Camera::Move(Direction dir, float deltaTime) {
	float d_speed = move_speed * deltaTime;
	glm::vec3 facing;
	switch(dir){
	case Direction::FORWARD:
		facing = front;
		break;
	case Direction::BACKWARD:
		facing = -front;
		break;
	case Direction::RIGHT:
		facing = -right;
		break;
	case Direction::LEFT:
		facing = right;
		break;
	}

	pos += facing * d_speed;
}

void Camera::Rotate(float xoffset, float yoffset, bool constrain = true) {
	xoffset *= look_speed;
	yoffset *= look_speed;

	yaw += xoffset;
	pitch += yoffset;

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

void Camera::Rotate(float x, float y, float z) {
	yaw   = x;
	pitch = y;
	roll  = z;
}