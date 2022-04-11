#include "OpenGL/Mesh.h"

Mesh::Mesh()
{
	vbo = new VertexBuffer();
	ibo = new IndexBuffer();
	vao = new VertexArray();
}

Mesh::~Mesh()
{
	delete vbo;
	delete ibo;
	delete vao;
}

void Mesh::SetVertexArray(VertexBufferLayout& layout) {
	vao->AddBuffer(*vbo, layout);
}

void Mesh::SetVertexBuffer(float* data, uint32_t size)
{
	vbo->SetData(data, size);
}

void Mesh::SetIndexBuffer(uint32_t* data, uint32_t size)
{
	ibo->SetData(data, size);
}

void Mesh::Bind() const
{
	vbo->Bind();
	vao->Bind();
	ibo->Bind();
}

void Mesh::Unbind() const
{
	vbo->Unbind();
	ibo->Unbind();
	vao->Unbind();
}
