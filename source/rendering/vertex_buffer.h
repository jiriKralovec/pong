#pragma once

class VertexBuffer
{
public:
    VertexBuffer(const void* data, unsigned int vertexCount);
    ~VertexBuffer();
    void Bind() const;
    void Unbind() const;
    unsigned int VertexCount() const { return m_vertexCount; }
private:
    unsigned int m_rendererId;
    unsigned int m_vertexCount;
};