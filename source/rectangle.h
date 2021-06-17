#pragma once
#include "abstract/shape.h"

class Rectangle : public Shape<4,6>
{
public:
    Rectangle(glm::vec2 size, glm::vec2 position) : Shape<4,6>(position), m_size(size)
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

        m_vertices[6] = m_position.x;
        m_vertices[7] = m_position.y + m_size.y;

        m_indices[0] = 0;
        m_indices[1] = 1;
        m_indices[2] = 2;

        m_indices[3] = 2;
        m_indices[4] = 3;
        m_indices[5] = 0;

    }
};