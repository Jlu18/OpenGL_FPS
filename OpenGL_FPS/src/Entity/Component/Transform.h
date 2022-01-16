#pragma once

#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Transform {
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;


	glm::mat4 GetTransformMatrix() const
	{
		glm::mat4 matrix{ 1.0f };

		matrix = glm::translate(matrix, position);

		matrix = glm::rotate(matrix, glm::radians(rotation.x), { 1.0f,0.0f,0.0f });
		matrix = glm::rotate(matrix, glm::radians(rotation.y), { 0.0f,1.0f,0.0f });
		matrix = glm::rotate(matrix, glm::radians(rotation.z), { 0.0f,0.0f,1.0f });

		matrix = glm::scale(matrix, scale);

		return matrix;
	};

	//static void Rotate(Transform& t, float dx, float dy, float dz) {
	//	t.rotation += glm::vec3{ dx,dy,dz };
	//}
	void Translate(glm::vec3 delta) {
		position += delta;
	}
	//static void Scale(Transform& t, float dx, float dy, float dz) {
	//	t.scale += glm::vec3
	//}
};

//Delete this once ECS version is working

//class Object {
//public:
//	Object() :position(0.f), rotation(0.f), scale(1.f), texture(nullptr), name("entity"){};
//
////Setter
//	void SetPosition(glm::vec3 new_pos) { position = new_pos; };
//	void Translate(glm::vec3 dt) { position += dt; };
//	void SetRotation(glm::vec3 new_rot) { rotation = new_rot; };
//	void SetScale(glm::vec3 new_scal) { scale = new_scal; };
//
//	void SetName(std::string name) { this->name = name; };
//	void SetTexture(Texture2D* texture) { this->texture = texture; };
//
////Getter
//	glm::vec3 GetPosition() { return position; };
//	glm::vec3 GetRotation() { return rotation; };
//	glm::vec3 GetScale()    { return scale;    };
//	glm::mat4 GetTransformMatrix();
//
//	std::string GetName() { return name; };
//	Texture2D* GetTexture() { return texture; };
//
//protected:
////General
//	std::string name;
////transformation of entity
//	glm::vec3 position;
//	glm::vec3 rotation;
//	glm::vec3 scale;
//
////temporary
//	Texture2D* texture;
//};	