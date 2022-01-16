#pragma once

#include "Entity/Component/Components.h"
#include "OpenGL/Mesh.h"

//purely for rendering a passed mesh with transformation, material, etc.
class Renderer {
public:
	static void Init();
	static void CleanUp();

	static void PreRender(const Camera& cam);
	static void PostRender();
	static void Clear(glm::vec3 bg);
	static void Render(const Transform& transform, const Renderable& renderable);
private:
	static Mesh* mesh;
};