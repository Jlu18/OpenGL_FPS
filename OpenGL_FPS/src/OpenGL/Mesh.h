#pragma once

#include "OpenGL/Buffer.h"
#include "OpenGL/VertexArray.h"


class Mesh {
private:
	VertexBuffer *vbo;
	IndexBuffer *ibo;
	VertexArray *vao;
public:
	Mesh();
	~Mesh();

	void SetVertexBuffer(float* data, uint32_t size);
	void SetVertexArray(VertexBufferLayout& layout);
	void SetIndexBuffer(uint32_t* data, uint32_t size);

	void Bind() const;
	void Unbind() const;
	inline uint32_t GetCount() const { return ibo->GetCount(); };
};