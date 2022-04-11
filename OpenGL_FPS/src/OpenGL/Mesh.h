#pragma once

#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include "OpenGL/Buffer.h"
#include "OpenGL/VertexArray.h"

/*
	Info stored for each vertex in mesh
*/
struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

/*
	Mesh class helps setup all necessary OpenGL call to pass the vertex, index buffer
		into GPU. 
*/
class Mesh {
private:
	VertexBuffer *vbo;
	IndexBuffer *ibo;
	VertexArray *vao;
public:
	Mesh();
	~Mesh();

	//Vertex Buffer
	void SetVertexBuffer(std::vector<Vertex> vertex);
	void SetVertexBuffer(float* data, uint32_t size);
	//Index Buffer
	void SetIndexBuffer(std::vector<uint32_t> index);
	void SetIndexBuffer(uint32_t* data, uint32_t size);
	//Vertex Array
	void SetVertexArray();
	void SetVertexArray(VertexBufferLayout& layout);

	void Bind() const;
	void Unbind() const;

	inline uint32_t GetCount() const { return ibo->GetCount(); };
};