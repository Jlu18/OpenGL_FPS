#include "Camera.h"

#include <iostream>
#include <cmath>

FPCamera::FPCamera(float fov, float width, float height){
	this->fov = fov;
	ratio = width / height;
	
	UpdateView();
	UpdateProj();
}

void FPCamera::UpdateView() {
	viewMatrix = glm::lookAt(position, position + front, up);
}

void FPCamera::UpdateProj() {
	projMatrix = glm::perspective(glm::radians(fov), ratio, 0.1f, 100.f);
}

//void FPCamera::CMoveForward(float value) {
//	/*
//		Multiplying direction of possible movement(x & z) with front and normalize it
//		which gives us normalized direction of where we are facing right and multiplying that
//		with value will give us the exact amount to translate the camera
//	*/
//	CTranslate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * front) * value);
//}
//
//void FPCamera::CMoveSideways(float value) {
//	/*
//		Cross product between front and up will give us right direction of camera
//		which we normalized and multiply with value will give us amount to move side by side
//		postive will mvoe right and negative will move left
//	*/
//	CTranslate(glm::normalize(glm::cross(front,up)) * value);
//}
//
//void FPCamera::CMoveUp(float value) {
//	CTranslate(up * value);
//}