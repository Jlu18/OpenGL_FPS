#include "Character.h"
#include "Raycast.h"

Character::Character()
{
	front = { 0.f, 0.f, 1.f };
	up = { 0.f, 1.f, 0.f };
	rotation.y = 90.f;
}

void Character::MoveForward()
{
	Translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * front) * speed);
}

void Character::MoveBackward()
{
	Translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * front) * -speed);
}

void Character::MoveRight()
{
	Translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * glm::cross(front, up)) * speed);
}

void Character::MoveUp()
{
	Translate(glm::vec3(0.0f, 1.0f, 0.0f) * speed);
}

void Character::MoveDown()
{
	Translate(glm::vec3(0.0f, 1.0f, 0.0f) * -speed);
}
//
//bool Character::CollidingFront(std::vector<std::shared_ptr<Entity>> entities)
//{
//	Box c_box = GetCollisionBox();
//	for (auto entity = entities.begin(); entity != entities.end(); entity++) {
//		Box e_box = (*entity)->GetCollisionBox();
//
//		if ((c_box.min.x <= e_box.max.x && c_box.max.x >= e_box.min.x) &&
//			(c_box.min.y <= e_box.max.y && c_box.max.y >= e_box.min.y) &&
//			(c_box.max.z >= e_box.min.z))
//			return true;
//	}
//	return false;
//}

std::shared_ptr<Entity> Character::CheckObjectLookingAt(std::vector<std::shared_ptr<Entity>> entities)
{
	return Ray::CheckFirstObjectHit(position,front,entities);
}

void Character::MoveLeft()
{
	Translate(glm::normalize(glm::vec3(1.0f, 0.0f, 1.0f) * glm::cross(front, up)) * -speed);
}