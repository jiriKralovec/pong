#pragma once

struct ShaderSource
{
    const char* vertex;
    const char* fragment;
};


class Shader
{
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
    void Bind() const;
    void Unbind() const;
    [[nodiscard]] unsigned int GetRendererId() const { return m_RendererId; }
private:
    void BuildShader();
    [[nodiscard]] unsigned int CompileSource(unsigned int type) const;
    void LoadSource(const char* path, unsigned int type);
private:
    unsigned int m_RendererId;
    ShaderSource m_Source;
};
