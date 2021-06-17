//
// Created by jrl on 17/06/2021.
//

#include "vertex_array.h"
#include "../util/logger.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

VertexArrayObject::VertexArrayObject()
{
    GLCall(glGenVertexArrays(1, &m_rendererId));
}
VertexArrayObject::~VertexArrayObject()
{
    GLCall(glDeleteVertexArrays(1, &m_rendererId));
}
void VertexArrayObject::AddBuffer(const VertexBuffer& vb) const
{

    Bind();
    vb.Bind();

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0,
            2,
            GL_FLOAT,
            GL_FALSE,
            sizeof(float) * 2,
            nullptr
    );

    vb.Unbind();
    Unbind();

}
void VertexArrayObject::Bind() const
{
    GLCall(glBindVertexArray(m_rendererId));
}
void VertexArrayObject::Unbind()
{
    GLCall(glBindVertexArray(0));
}