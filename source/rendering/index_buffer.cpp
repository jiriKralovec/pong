//
// Created by jrl on 17/06/2021.
//

#include "index_buffer.h"
#include "../util/logger.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

IndexBuffer::IndexBuffer() : m_rendererId(0), m_indexCount(0)
{ }
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_rendererId);
}
void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererId);
}
void IndexBuffer::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void IndexBuffer::LoadIndices(const void *data, unsigned int count)
{
    m_indexCount = count;

    glGenBuffers(1, &m_rendererId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}