#include "Character.h"
#include "Raycast.h"

Character::Character()
{
	front = { 0.f, 0.f, 1.f };
	up = { 0.f, 1.f, 0.f };
	velocity = { 0.f, 0.f, 0.f };
	rotation.y = 90.f;
}

void Character::Move() {
	Translate(velocity.z * front*speed);
	Translate(velocity.x * glm::cross(front,up)*speed);
	Translate(velocity.y * glm::vec3(0.0f,1.0f,0.0f)*speed);
}

std::shared_ptr<Collidable> Character::CheckObjectLookingAt(std::vector<std::shared_ptr<Collidable>> entities)
{
	return Ray::CheckFirstObjectHit(position,front,entities);
}