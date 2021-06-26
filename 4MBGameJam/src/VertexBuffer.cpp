#include "VertexBuffer.h"
#include "Util.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    GLCall(glGenBuffers(1, &m_RendererID));                                 //Generate empty buffer
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));                    //Bind buffer to set it as the current buffer in OpenGL's state machine -> this set what will drawn on the screen
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));      //Copy the points into current boundbuffer
}

VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
