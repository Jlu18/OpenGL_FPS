#include "Component/Player.h"
#include "Resource/Setting.h"

// /*
// 	Rotate the character based on the x and y movement
// */
// void Player::OnMouseMove(float xrel, float yrel)
// {
// 	//Update the rotation in character.h
// 	//xrel is apply to yaw because xrel is horizontal movement which rotates character in y-axis(yaw)
// 	//yrel is apply to pitch because yrel is vertical movement which rotates character in x-axis(pitch)
// 	rotation.x -= yrel; //pitch
// 	rotation.y += xrel; //yaw

// 	//constrain
// 	if (rotation.x >  89.0f)
// 		rotation.x =  89.0f;
// 	if (rotation.x < -89.0f)
// 		rotation.x = -89.0f;;

// 	// calculate the new Front vector
// 	glm::vec3 new_front{ 0.0f };
// 	new_front.x = cos(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
// 	new_front.y = sin(glm::radians(rotation.x));
// 	new_front.z = sin(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
// 	front = glm::normalize(new_front);

// 	glm::vec3 right = glm::normalize(glm::cross(front, { 0.0f,1.0f,0.0f }));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
// 	up = glm::normalize(glm::cross(right, front));
// }

