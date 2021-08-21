#include "Character.h"

Character::Character(): Entity()
{
	front = { 0.f, 0.f, -1.f };
}

void Character::MoveForward()
{
	Translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * front) * speed_forward);
}

void Character::MoveBackward()
{
	Translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * front) * -speed_backward);
}

void Character::MoveRight()
{
	Translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * glm::cross(front, { 0.0f, 1.0f, 0.0f })) * speed_sideways);
}

void Character::MoveLeft()
{
	Translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * glm::cross(front, { 0.0f, 1.0f, 0.0f })) * -speed_sideways);
}