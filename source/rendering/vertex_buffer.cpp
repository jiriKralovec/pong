//
// Created by jrl on 17/06/2021.
//

#include "vertex_buffer.h"
#include "../util/logger.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

VertexBuffer::VertexBuffer(): m_rendererId(0), m_vertexCount(0)
{ }
VertexBuffer::~VertexBuffer()
{
    GLCall(glDeleteBuffers(1, &m_rendererId));
}
void VertexBuffer::Bind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
}
void VertexBuffer::Unbind() const
{
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
void VertexBuffer::LoadGeometry(const void* data, unsigned int count)
{
    m_vertexCount = count;

    GLCall(glGenBuffers(1, &m_rendererId));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
    GLCall(glBufferData(GL_ARRAY_BUFFER, count * 2 * sizeof(float), data, GL_STATIC_DRAW));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}