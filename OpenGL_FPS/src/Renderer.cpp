#pragma once

#include "Renderer.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Box.h"
#include "ResourceManager.h"
#include "Util.h"

Shader* Renderer::shader = nullptr;
VertexBuffer* Renderer::vb_box = nullptr;
IndexBuffer* Renderer::ib_box = nullptr;
VertexArray* Renderer::va_box = nullptr;
VertexBufferLayout* Renderer::vbl_box = nullptr;

void Renderer::Init()
{
	//Resource Loader
	ResourceManager::LoadShader("res/shader/Basic.shader", "basic");
	shader = ResourceManager::GetShader("basic");
	
	vb_box = new VertexBuffer(verts, v_count*sizeof(float));
	//ib_box = new IndexBuffer(indices, i_count);
	vbl_box = new VertexBufferLayout();
	
	vbl_box->Push<float>(3);

	va_box = new VertexArray();
	va_box->AddBuffer(*vb_box,*vbl_box);
}

void Renderer::CleanUp()
{
	delete vb_box;
	delete va_box;
	delete vbl_box;
}

void Renderer::Bind() {
	shader->Bind();
	vb_box->Bind();
	va_box->Bind();
}

//draw box only now
void Renderer::Render(Entity* entity,glm::mat4 projViewMat)
{
	shader->SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
	shader->SetUniformMat4fv("u_Matrix", projViewMat * entity->GetTransformMatrix());//);
	GLCall(glDrawArrays(GL_TRIANGLES,0,36));
}

