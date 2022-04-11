#pragma once
#include "Renderer.h"

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Renderer/Primitive/Box.h"
#include "Resource/ResourceManager.h"
#include "Resource/Setting.h"
#include "Util.h"

struct QuadVertex {
	glm::vec3 Position;
	glm::vec4 Color;
	//glm::vec2 TexCoord;
};

struct RenderData {
	Shader* shader;
};

static RenderData  r_data;
Mesh* Renderer::mesh = nullptr;

void Renderer::Init()
{
	//TEMP: Mesh (Box) init
	mesh = new Mesh();
	mesh->SetVertexBuffer(Box::verts, sizeof(float) * Box::v_count);

	VertexBufferLayout layout;
	layout.Push<float>(3);
	mesh->SetVertexArray(layout);

	mesh->SetIndexBuffer(Box::indices, Box::i_count);
	
	//Resource Loader
	r_data.shader = ResourceManager::LoadShader("res/shader/Basic.shader", "basic");

	GLCall(glViewport(0, 0, Setting::WIDTH, Setting::HEIGHT));
	GLCall(glEnable(GL_DEPTH_TEST));
}

void Renderer::CleanUp()
{
	ResourceManager::Clear();
	r_data.shader = nullptr;
	delete mesh;
	mesh = nullptr;
}

void Renderer::PreRender(const Camera& cam) {
	r_data.shader->Bind();
	r_data.shader->SetUniformMat4fv("u_ViewProjMatrix", cam.GetViewProjMatrix());

	mesh->Bind();
}

void Renderer::PostRender() {
	r_data.shader->UnBind();
	mesh->Unbind();
}


//draw box only now
void Renderer::Render(const Transform& transform, const Renderable& renderable)
{
	r_data.shader->SetUniform4fv("u_Color", renderable.color);
	r_data.shader->SetUniformMat4fv("u_Matrix", transform.GetTransformMatrix());

	GLCall(glDrawElements(GL_TRIANGLES, mesh->GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear(glm::vec3 bg)
{
	GLCall(glClearColor(bg.x, bg.y, bg.z, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}
