#pragma once

#include "Renderer.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Box.h"
#include "ResourceManager.h"
#include "Util.h"

Shader* Renderer::shader = nullptr;
Shader* Renderer::shader_texture = nullptr; 

VertexBuffer* Renderer::vb_box = nullptr;
IndexBuffer* Renderer::ib_box = nullptr;
VertexArray* Renderer::va_box = nullptr;
VertexBufferLayout* Renderer::vbl_box = nullptr;

void Renderer::Init()
{
	//Resource Loader
	ResourceManager::LoadShader("res/shader/Basic.shader", "basic");
	ResourceManager::LoadShader("res/shader/Texture.shader", "texture");
	shader = ResourceManager::GetShader("basic");
	shader_texture = ResourceManager::GetShader("texture");
	
	vb_box = new VertexBuffer(vertices_texture, sizeof(vertices_texture));
	//ib_box = new IndexBuffer(indices, i_count);
	vbl_box = new VertexBufferLayout();
	
	vbl_box->Push<float>(3);
	vbl_box->Push<float>(2);

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
	vb_box->Bind();
	va_box->Bind();
}

//draw box only now
void Renderer::Render(std::vector<std::shared_ptr<Entity>> entities,glm::mat4 projViewMat)
{
	Bind();
	shader->Bind();
	shader->SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);

	for (std::vector<std::shared_ptr<Entity>>::iterator entity = entities.begin(); entity != entities.end(); entity++) {
		shader->SetUniformMat4fv("u_Matrix", projViewMat * (*entity)->GetTransformMatrix());
		GLCall(glDrawArrays(GL_TRIANGLES,0,36));
	}
}

void Renderer::RenderTexture(std::vector<std::shared_ptr<Entity>> entities, glm::mat4 projViewMat) 
{	
	Bind();
	shader_texture->Bind();

	for (std::vector<std::shared_ptr<Entity>>::iterator entity = entities.begin(); entity != entities.end(); entity++) {
		Texture2D* texture = (*entity)->GetTexture();
		if (texture != nullptr) {
			texture->Bind();
			shader->SetUniformMat4fv("u_Matrix", projViewMat * (*entity)->GetTransformMatrix());//);
			GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
		}
	}
}