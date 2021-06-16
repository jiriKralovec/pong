#include "logger.h"
#include "GL/glew.h"

void LogMessage(const char* message, const char* file, const uint16_t line)
{
    std::cout << file << ":" << line << " " << message << std::endl;
}

void GlClearError()
{
    while (GLenum error = glGetError() != GL_NO_ERROR)
    {
        std::cout << "glError: " << error << std::endl;
    }
}

bool GlLogCall(const char* fn, const char* file, uint16_t line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "): " << fn << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}