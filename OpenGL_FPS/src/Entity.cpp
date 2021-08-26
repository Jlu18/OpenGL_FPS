#include "glm/gtc/matrix_transform.hpp"

#include "Entity.h"

glm::mat4 Entity::GetTransformMatrix()
{
	glm::mat4 matrix{ 1.0f };
	
	matrix = glm::translate(matrix, position);

	matrix = glm::rotate(matrix, glm::radians(rotation.x), { 1.0f,0.0f,0.0f });
	matrix = glm::rotate(matrix, glm::radians(rotation.y), { 0.0f,1.0f,0.0f });
	matrix = glm::rotate(matrix, glm::radians(rotation.z), { 0.0f,0.0f,1.0f });

	matrix = glm::scale(matrix, scale);

	return matrix;
}

Box Entity::GetCollisionBoxes()
{
	//TODO - Count rotation by apply rotation matrix
	return {
		position - scale/2.0f, //min
		position + scale/2.0f  //max
	} ;
}
