#pragma once

class VertexBuffer
{
public:
    VertexBuffer();
    ~VertexBuffer();
    void Bind() const;
    void Unbind() const;
    void LoadGeometry(const void* data, unsigned int count);
    unsigned int VertexCount() const { return m_vertexCount; }
private:
    unsigned int m_rendererId;
    unsigned int m_vertexCount;
};