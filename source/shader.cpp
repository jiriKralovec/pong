#include "shader.h"
#include "util/logger.h"
#include "util/file.h"
#include "GL/glew.h"

#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>

/** New shader */
Shader::Shader(const char *vertexPath, const char *fragmentPath) {

    LoadSource(vertexPath, GL_VERTEX_SHADER);
    LoadSource(fragmentPath, GL_FRAGMENT_SHADER);

    BuildShader();

}
Shader::~Shader() = default;
void Shader::Bind() const {
    GLCall(glUseProgram(m_RendererId));
}
void Shader::Unbind() const {
    GLCall(glUseProgram(0));
}
void Shader::LoadSource(const char *path, unsigned int type) {

    std::ifstream inputFile;
    inputFile.open(path);

    std::stringstream inputStream;
    inputStream << inputFile.rdbuf();

    std::string outString = inputStream.str();

    inputFile.close();

    if(type == GL_VERTEX_SHADER)
    {
        //m_Source.vertex = outString.c_str();
        m_Source.vertex = "#version 330\n"
                          "\n"
                          "layout (location = 0) in vec3 verPos;\n"
                          "\n"
                          "uniform mat4 uProjection;\n"
                          "\n"
                          "void main() {\n"
                          "    gl_Position = uProjection * vec4(verPos, 1.0);\n"
                          "}";
    }
    else
    {
        //m_Source.fragment = outString.c_stsr();
        m_Source.fragment = "#version 330\n"
                            "\n"
                            "out vec4 fragColor;\n"
                            "\n"
                            "void main() {\n"
                            "    fragColor = vec4(1.0);\n"
                            "}";
    }

}
void Shader::BuildShader() {

    GLCall(m_RendererId = glCreateProgram());

    GLCall(uint32_t vertex = CompileSource(GL_VERTEX_SHADER));
    GLCall(uint32_t fragment = CompileSource(GL_FRAGMENT_SHADER));

    GLCall(glAttachShader(m_RendererId, vertex));
    GLCall(glAttachShader(m_RendererId, fragment));

    GLCall(glLinkProgram(m_RendererId));
    GLCall(glValidateProgram(m_RendererId));

    GLCall(glDeleteShader(vertex));
    GLCall(glDeleteShader(fragment));

}
unsigned int Shader::CompileSource(unsigned int type) const
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
