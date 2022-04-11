#pragma once

#include <glm/gtc/matrix_transform.hpp>

class Renderer2D {
private:
public:
	static void Init();
	static void CleanUp();

	static void DrawQuad(glm::mat4 transform, const glm::vec4& color);
};