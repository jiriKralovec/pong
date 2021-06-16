#include "shader.h"
#include "util/logger.h"
#include "GL/glew.h"

Shader::Shader() : m_Source(ShaderSource
    {
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "uniform mat4 projection;\n"
            "void main() { gl_Position = projection * vec4(aPos, 1.0f); }\n",
            "#version 330 core\n"
            "void main() { gl_FragColor = vec4(1.0f); }\n"
    })
{
    LoadShader();
}
Shader::~Shader() = default;
void Shader::Bind() const
{
    GLCall(glUseProgram(m_RendererId));
}
void Shader::Unbind() const
{
    GLCall(glUseProgram(0));
}
void Shader::LoadShader()
{
    GLCall(m_RendererId = glCreateProgram());

    GLCall(uint32_t vertex = CompileShader(GL_VERTEX_SHADER));
    GLCall(uint32_t fragment = CompileShader(GL_FRAGMENT_SHADER));

    GLCall(glAttachShader(m_RendererId, vertex));
    GLCall(glAttachShader(m_RendererId, fragment));

    GLCall(glLinkProgram(m_RendererId));
    GLCall(glValidateProgram(m_RendererId));

    GLCall(glDeleteShader(vertex));
    GLCall(glDeleteShader(fragment));

}
uint32_t Shader::CompileShader(GLenum type)
{
    GLCall(uint32_t shader = glCreateShader(type));

    /** Load source */
    GLCall(
    glShaderSource(
            shader,
            1,
            type == GL_VERTEX_SHADER ? &m_Source.vertex : &m_Source.fragment,
            nullptr
        )
    );

    GLCall(glCompileShader(shader));

    // get compilation result
    int result;
    GLCall(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));

    if(result == GL_FALSE)
    {
        // get message length to allocate buffer
        int len;
        GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len));

        // pull message
        char* message = (char*) alloca(len * sizeof(char));
        GLCall(glGetShaderInfoLog(shader, len, &len, message));

        std::cout << "Failed to compile a shader: ";
        std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment");
        std::cout << " shader failed to compile with error message: '" << message << "'";
        std::cout << std::endl;

        /** cleanup */
        delete message;
        GLCall(glDeleteShader(shader));

        return 0;

    }

    return shader;

}