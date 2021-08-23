#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "Character.h"

//Based from https://learnopengl.com 
//https://learnopengl.com/code_viewer_gh.php?code=includes/learnopengl/camera.h
class FPCamera : public Character {
public:
	FPCamera(float fov, float width, float height);
	glm::mat4 GetViewProjMatrix() { return projMatrix * viewMatrix; };
protected:
	void UpdateView();
	void UpdateProj();

private:
	//proj matrix attrib
	float fov;
	float ratio;
	//view matrix attrib are included in Character and Entity (position, front, and up)

	glm::mat4 projMatrix;
	glm::mat4 viewMatrix;
};
