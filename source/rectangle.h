#pragma once

class Rectangle
{
public:
    Rectangle(float width, float height, float x, float y)
        : m_width(width), m_height(height), m_x(x), m_y(y)
    {
        UpdateBuffer();
    }
    void Draw() const
    {
        Renderer::getInstance().DrawAsArrays(m_rendererId);
    }
private:
    void UpdateBuffer()
    {
        if(m_rendererId == 0)
            GLCall(glGenBuffers(1, &m_rendererId));

        // Update vertices
        /*
        m_vertices[0] = m_x;
        m_vertices[1] = m_y;

        m_vertices[2] = m_x + m_width;
        m_vertices[3] = m_y;

        m_vertices[4] = m_x + m_width;
        m_vertices[5] = m_y - m_height;
         */

        /*
        m_vertices[6] = m_x;
        m_vertices[7] = m_y - m_height;
        */

        GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
        GLCall(glBufferData(GL_ARRAY_BUFFER, 1 * 6 * sizeof(float), &m_vertices, GL_STATIC_DRAW));

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
    uint32_t m_rendererId = 0;
    float m_width;
    float m_height;
    float m_x;
    float m_y;
    float m_vertices[3 * 2] { 0.0f, 0.0f, 25.0f, 0.0f, 25.0f, 25.0f };
};