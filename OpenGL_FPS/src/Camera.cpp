#include "Camera.h"

#include <iostream>
#include <cmath>

Camera::Camera(float fov, float width, float height){
	sens = 0.5f;
	this->fov = fov;
	ratio = width / height;
	
	pos   = { 0.f, 0.f,  0.f };
	up    = { 0.f, 1.f,  0.f };
	front = { 0.f, 0.f,  1.f };

	pitch = 0.0f;
	yaw = -90.f;

	UpdateView();
	UpdateProj();
}

void Camera::CMoveForward(float value) {
	/*
		Multiplying direction of possible movement(x & z) with front and normalize it
		which gives us normalized direction of where we are facing right and multiplying that
		with value will give us the exact amount to translate the camera
	*/
	CTranslate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * front) * value);
}

void Camera::CMoveSideways(float value) {
	/*
		Cross product between front and up will give us right direction of camera
		which we normalized and multiply with value will give us amount to move side by side
		postive will mvoe right and negative will move left
	*/
	CTranslate(glm::normalize(glm::cross(front,up)) * value);
}

void Camera::CMoveUp(float value) {
	CTranslate(up * value);
}

void Camera::UpdateView() {
	viewMatrix = glm::lookAt(pos, pos + front, up);
}

void Camera::UpdateProj() {
	projMatrix = glm::perspective(glm::radians(fov), ratio, 0.1f, 100.f);
}

void Camera::CRotate(float xrel, float yrel, bool constrain) {
	yaw += xrel * sens;
	pitch -= yrel * sens;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrain)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}

	//std::cout << yaw << " " << pitch << std::endl;

	// calculate the new Front vector
	glm::vec3 new_front{ 0.0f };
	new_front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	new_front.y = sin(glm::radians(pitch));
	new_front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(new_front);
	
	glm::vec3 right = glm::normalize(glm::cross(front, { 0.0f,1.0f,0.0f }));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up = glm::normalize(glm::cross(right, front));
	UpdateView();
}