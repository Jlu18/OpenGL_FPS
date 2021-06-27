#ifndef CAMERA_H
#define CAMERA_H

#include <glm/gtc/matrix_transform.hpp>

enum class Direction { STOP,FORWARD,BACKWARD,RIGHT,LEFT };

//Based from https://learnopengl.com 
//https://learnopengl.com/code_viewer_gh.php?code=includes/learnopengl/camera.h
class Camera {
	glm::vec3 pos;
	glm::vec3 up;
	glm::vec3 front;
	glm::vec3 right;

	float pitch, yaw, roll; //euler angle: x,y,z
	float move_speed;
	float look_speed;

	float fov;      //in radian
	float aspectRatio;
	void UpdateRotation();
public:
	Camera();
	
	glm::mat4 GetViewMatrix() { return glm::lookAt(pos, pos + front, up);};

	void Move(Direction dir, float deltaTime);
	void Rotate(float xoffset, float yoffset, bool constrain);
	void Rotate(float x, float y, float z);
};

#endif