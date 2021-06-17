#pragma once
#include "glm.hpp"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "../util/logger.h"
#include "../renderer.h"

template<size_t VertexCount>
class Shape
{
public:
    Shape(glm::vec2 position) : m_position(position), m_origin({0.5f, 0.5f}), m_scale({1.0f, 1.0f})
    {

    }
    void Draw() const
    {
        Renderer::getInstance().Draw(m_vertexBuffer);
    }
protected:
    void AttachVertexBufferData()
    {
        if(m_vertexBuffer == 0)
            GLCall(glGenBuffers(1, &m_vertexBuffer));

        GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer));
        GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), &m_vertices, GL_STATIC_DRAW));

        GLCall(glEnableVertexAttribArray(0));
        GLCall(glVertexAttribPointer(
                0,
                2,
                GL_FLOAT,
                GL_FALSE,
                sizeof(float) * 2,
                nullptr
        ));

        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));

    }
private:
    unsigned int m_vertexBuffer{};
protected:
    float m_vertices[VertexCount]{};
    glm::vec2 m_position;
    glm::vec2 m_origin;
    glm::vec2 m_scale;
};