#pragma once

#include <string>

struct Renderable {
	std::string texture = "";
	//std::string mesh_type(or model name) = "square";
	glm::vec4 color = { 1.0f, 0.0f, 0.0f, 1.0f };
};