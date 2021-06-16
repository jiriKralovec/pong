#pragma once

struct ShaderSource
{
    const char* vertex;
    const char* fragment;
};

class Shader
{
public:
    Shader();
    ~Shader();
    void Bind() const;
    void Unbind() const;
private:
    void LoadShader();
    unsigned int CompileShader(unsigned int type);
private:
    unsigned int m_RendererId;
    ShaderSource m_Source;
};