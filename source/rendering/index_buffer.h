#pragma once

class IndexBuffer {
public:
    IndexBuffer();
    ~IndexBuffer();
    void Bind() const;
    static void Unbind();
    void LoadIndices(const void* data, unsigned int count);
    unsigned int IndexCount() const { return m_indexCount; }
private:
    unsigned int m_rendererId;
    unsigned int m_indexCount;
};