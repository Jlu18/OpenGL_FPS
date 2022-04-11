#include "Mesh.h"

/*
	Constructor for Mesh class
		allocate memory for vertex buffer, index buffer, and vertex array
		TODO: should use unique_ptr?
*/
Mesh::Mesh()
{
	vbo = new VertexBuffer();
	ibo = new IndexBuffer();
	vao = new VertexArray();
}

/*
	Destructor for Mesh class
		deallocate allocated memories
*/
Mesh::~Mesh()
{
	delete vbo;
	delete ibo;
	delete vao;
}

/*
	Set vertex buffer object that's supplied by struct Vertex in vector form
*/
void Mesh::SetVertexBuffer(std::vector<Vertex> vertices)
{
	//pass vertex buffer data
	vbo->SetData(&vertices[0], vertices.size() * sizeof(Vertex));
}

/*
	Set vertex buffer object that's supplied as float pointer and size
*/
void Mesh::SetVertexBuffer(float* data, uint32_t size)
{
	vbo->SetData(data, size);
}

/*
	Set index buffer object
*/
void Mesh::SetIndexBuffer(std::vector<uint32_t> index)
{
}
void Mesh::SetIndexBuffer(uint32_t* data, uint32_t size)
{
	ibo->SetData(data, size);
}

/*
	Default Vertex Array function where it set layout for struct Vertex
	which is position(3 float), normal(3 float), and texCoord(2 float)
*/
void Mesh::SetVertexArray() {
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	layout.Push<float>(2);

	vao->AddBuffer(*vbo, layout);
}

/*
	Custom vertex array function where it pass down layout down to vertex array object
*/
void Mesh::SetVertexArray(VertexBufferLayout& layout) {
	vao->AddBuffer(*vbo, layout);
}

/*
	Bind all objects
*/
void Mesh::Bind() const
{
	vbo->Bind();
	vao->Bind();
	ibo->Bind();
}

/*
	UnBind all objects
*/
void Mesh::Unbind() const
{
	vbo->Unbind();
	ibo->Unbind();
	vao->Unbind();
}
