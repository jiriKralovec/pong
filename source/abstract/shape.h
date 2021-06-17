#pragma once
#include "glm.hpp"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "../util/logger.h"
#include "../renderer.h"
#include "game_object.h"

#include "../rendering/vertex_buffer.h"
#include "../rendering/vertex_array.h"

template<size_t VertexCount>
class Shape : public GameObject
{
public:
    explicit Shape(glm::vec2 position)
        : GameObject(), m_position(position), m_origin({0.5f, 0.5f}), m_scale({1.0f, 1.0f})
    { }
    virtual void Draw() const
    {
        Renderer::getInstance().Draw(m_vao);
    }
    virtual void Update() { }
protected:
    void BuildBuffers()
    {
        m_vb.LoadGeometry(m_vertices, VertexCount);
        m_vao.AddBuffer(m_vb);
    }
private:
    VertexBuffer m_vb;
    VertexArrayObject m_vao;
protected:
    float m_vertices[VertexCount * 2];
    glm::vec2 m_position;
    glm::vec2 m_origin;
    glm::vec2 m_scale;
};