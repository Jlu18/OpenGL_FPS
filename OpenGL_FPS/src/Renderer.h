#pragma once
#include "Entity.h"
#include "Camera.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"

class Renderer {
public:
	static void Init();
	static void CleanUp();
	static void Render(std::vector<std::shared_ptr<Entity>> entities, glm::mat4 projViewMat);
	static void RenderTexture(std::vector<std::shared_ptr<Entity>> entities, glm::mat4 projViewMat);
	static void Bind();
	
private:
	static Shader* shader;
	static Shader* shader_texture;

	static VertexBuffer* vb_box;
	static IndexBuffer* ib_box;
	static VertexArray* va_box;
	static VertexBufferLayout* vbl_box;
	
	
};