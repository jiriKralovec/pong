//
// Created by jrl on 17/06/2021.
//

#include "vertex_buffer.h"
#include "../util/logger.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int vertexCount): m_rendererId(0), m_vertexCount(vertexCount)
{
    glGenBuffers(1, &m_rendererId);
    glBindBuffer(GL_ARRAY_BUFFER, m_rendererId);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 2 * sizeof(float), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
VertexBuffer::~VertexBuffer()
{

}
void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_rendererId);
}
void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}