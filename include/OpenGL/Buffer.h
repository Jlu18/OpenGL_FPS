#pragma once

#include "OpenGL/VertexBufferLayout.h"

class VertexBuffer {

private:
	uint32_t m_RendererID;
	VertexBufferLayout m_Layout;
public:
	VertexBuffer():VertexBuffer(0) {};
	VertexBuffer(uint32_t size);
	VertexBuffer(const void *data, uint32_t size);

	~VertexBuffer();

	void SetData(const void *data, uint32_t size);
	void SetLayout(const VertexBufferLayout& layout) { m_Layout = layout; };

	VertexBufferLayout& GetLayout() { return m_Layout; };

	void Bind() const;
	void Unbind() const;
};

class IndexBuffer {
private:
	uint32_t m_RendererID;
	uint32_t m_Count;
public:
	IndexBuffer();
	IndexBuffer(const uint32_t* data, uint32_t count);
	~IndexBuffer();

	void SetData(const uint32_t* data, uint32_t count);

	void Bind() const;
	void Unbind() const;

	inline uint32_t GetCount() const { return m_Count; }
};