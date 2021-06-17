#pragma once
#include "vertex_buffer.h"

class VertexArrayObject
{
public:
    VertexArrayObject();
    ~VertexArrayObject();
    void AddBuffer(const VertexBuffer& vb) const;
    void Bind() const;
    static void Unbind();
private:
    unsigned int m_rendererId;
};