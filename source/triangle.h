#pragma once
#include "abstract/shape.h"

class Triangle : public Shape<3>
{
public:
    Triangle(glm::vec2 size, glm::vec2 position) : Shape<3>(position), m_size(size)
    {
        BuildGeometry();
        BuildBuffers();
    }
private:
    glm::vec2 m_size;
private:
    void BuildGeometry()
    {
        m_vertices[0] = m_position.x;
        m_vertices[1] = m_position.y;

        m_vertices[2] = m_position.x + m_size.x;
        m_vertices[3] = m_position.y;

        m_vertices[4] = m_position.x + m_size.x;
        m_vertices[5] = m_position.y + m_size.y;
    }
};