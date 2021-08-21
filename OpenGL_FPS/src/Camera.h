#pragma once

#include <glm/gtc/matrix_transform.hpp>



//Based from https://learnopengl.com 
//https://learnopengl.com/code_viewer_gh.php?code=includes/learnopengl/camera.h
class Camera {
public:
	Camera(float fov, float width, float height);
	
	void CMoveForward(float value);
	void CMoveSideways(float value);
	void CMoveUp(float value);

	void CSetPosition(glm::vec3 v) { pos = v; };
	void CRotate(float xoffset, float yoffset, bool constrain = true);
	void CTranslate(glm::vec3 v) { pos += v; };

	void SetFOV(float fov) { this->fov = fov; UpdateProj(); };

	glm::mat4 GetViewProjMatrix() { return projMatrix * viewMatrix; };

protected:
	glm::mat4 projMatrix;
	glm::mat4 viewMatrix;
//view matrix attrib
	glm::vec3 pos;
	glm::vec3 up;
	glm::vec3 front;

	float yaw, pitch; //roll
	float sens;
//proj matrix attrib
	float fov;
	float ratio;

private:
	void UpdateView();
	void UpdateProj();
};
