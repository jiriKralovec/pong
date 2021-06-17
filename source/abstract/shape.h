#pragma once
#include "glm.hpp"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "../util/logger.h"
#include "../renderer.h"
#include "game_object.h"
#include "../rendering/vertex_buffer.h"

template<size_t VertexCount>
class Shape : public GameObject
{
public:
    explicit Shape(glm::vec2 position)
        : GameObject(), m_position(position), m_origin({0.5f, 0.5f}), m_scale({1.0f, 1.0f}), m_vb(nullptr)
    { }
    virtual void Draw() const
    {

        m_vb->Bind();

        GLCall(glEnableVertexAttribArray(0));
        GLCall(glVertexAttribPointer(
                0,
                2,
                GL_FLOAT,
                GL_FALSE,
                sizeof(float) * 2,
                nullptr
        ));

        Renderer::getInstance().Draw(m_vb);

        m_vb->Unbind();

    }
    virtual void Update() { }
protected:
    void BuildBuffers()
    {
        m_vb = new VertexBuffer(m_vertices, VertexCount);
    }
private:
    VertexBuffer* m_vb;
protected:
    float m_vertices[VertexCount * 2];
    glm::vec2 m_position;
    glm::vec2 m_origin;
    glm::vec2 m_scale;
};