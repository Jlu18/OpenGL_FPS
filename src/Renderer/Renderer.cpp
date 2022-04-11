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
Model* model = nullptr;

void Renderer::Init()
{
	//TEMP: Mesh (Box) init
	mesh = new Mesh();
	
	//Pass Vertex and Index to the Buffers
	mesh->SetVertexBuffer(Box::vertices, sizeof(float) * Box::v_count);
	mesh->SetIndexBuffer(Box::indices, Box::i_count);


	//Describe the layout of the vertex buffer (ie. 3 vertices and 3 normals)
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	mesh->SetVertexArray(layout);



	//model = ResourceManager::LoadModel("res/model/teapot.obj", "teapot");
	
	//Resource Loader
	//r_data.shader = ResourceManager::LoadShader("res/shader/Basic.shader", "basic");
	r_data.shader = ResourceManager::LoadShader("res/shader/3D.shader", "3D");


	GLCall(glViewport(0, 0, Setting::WIDTH, Setting::HEIGHT));
	GLCall(glEnable(GL_DEPTH_TEST));
}

void Renderer::CleanUp()
{
	ResourceManager::Clear();
	r_data.shader = nullptr;

	delete mesh;
	mesh = nullptr;

	delete model;
	model = nullptr;
}

void Renderer::PreRender(const Camera& cam) {
	r_data.shader->Bind();
	r_data.shader->SetUniformMat4fv("u_ViewProjMatrix", cam.GetViewProjMatrix());
	
	if (model) model->Bind();
	else mesh->Bind();
}

void Renderer::PostRender() {
	r_data.shader->UnBind();
	if (model) model->Unbind();
	else mesh->Unbind();
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
