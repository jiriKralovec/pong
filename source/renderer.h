#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "util/logger.h"
#include "shader.h"
#include "glm.hpp"
#include "rendering/vertexbuffer.h"

class Renderer
{
public:
    int CreateWindowIfNotExists(uint32_t width, uint32_t height, const char* title);
    [[nodiscard]] bool ShouldCurrentWindowClose() const;
    [[nodiscard]] GLFWwindow& GetCurrentWindowInstance() const { return *m_window; }
    [[nodiscard]] const Shader& GetMainShaderInstance();
    void SetRenderingContext() const;
    void Draw(const VertexBuffer* vb) const;
public:
    static Renderer& getInstance();
    static void freeInstanceIfAny();
private:
    Renderer();
    ~Renderer();
private:
    static Renderer* m_instance;
    GLFWwindow* m_window;
    uint32_t m_windowWidth;
    uint32_t m_windowHeight;
    Shader* m_shader;
};