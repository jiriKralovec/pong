#pragma once
#include "abstract/shape.h"

class Triangle : public Shape<6>
{
public:
    Triangle(glm::vec2 size, glm::vec2 position) : Shape<6>(position)
    {
        m_vertices[0] = position.x;
        m_vertices[1] = position.y;

        m_vertices[2] = position.x + size.x;
        m_vertices[3] = position.y;

        m_vertices[4] = position.x + size.x;
        m_vertices[5] = position.y + size.y;

        AttachVertexBufferData();
    }
};