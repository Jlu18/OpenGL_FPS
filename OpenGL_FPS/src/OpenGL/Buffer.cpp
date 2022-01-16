#include "OpenGL/Buffer.h"
#include "Util.h"

//VertexBuffer
VertexBuffer::VertexBuffer(uint32_t size)
{
    GLCall(glGenBuffers(1, &m_RendererID));                                 //Generate empty buffer
    //GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));                    //Bind buffer to set it as the current buffer in OpenGL's state machine -> this set what will drawn on the screen
    //GLCall(glBufferData(GL_ARRAY_BUFFER, size, 0, GL_STATIC_DRAW));         //Copy the points into current boundbuffer
}

VertexBuffer::VertexBuffer(const void* data, uint32_t size)
{
    GLCall(glGenBuffers(1, &m_RendererID));                                 //Generate empty buffer
    Bind();                                                                 //Bind buffer to set it as the current buffer in OpenGL's state machine -> this set what will drawn on the screen
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));      //Copy the points into current boundbuffer
    Unbind();
}

VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::SetData(const void* data, uint32_t size) {
    Bind();
    //Avoid if we are updating often (ie. every frame)
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    Unbind();
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}


//Index Buffer
IndexBuffer::IndexBuffer():m_Count(0) {
    ASSERT(sizeof(uint32_t) == sizeof(GLuint));
    GLCall(glGenBuffers(1, &m_RendererID));
}
IndexBuffer::IndexBuffer(const uint32_t* data, uint32_t count) 
    : m_Count(count)
{
    ASSERT(sizeof(uint32_t) == sizeof(GLuint));

    GLCall(glGenBuffers(1, &m_RendererID));
    Bind();
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, GL_STATIC_DRAW));
    Unbind();
}

IndexBuffer::~IndexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::SetData(const uint32_t* data, uint32_t count)
{
    m_Count = count;
    Bind();
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, GL_STATIC_DRAW));
    Unbind();
}

void IndexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
