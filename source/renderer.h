#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "util/logger.h"
#include "shader.h"
#include "glm.hpp"

class Renderer
{
public:
    void BindMvp(const Shader& shader) const;

    void DrawAsArrays(unsigned int rendererId);

    [[nodiscard]] bool isWindowInitialized() const { return m_window != nullptr; }
    [[nodiscard]] bool isInitialized() const { return m_initialized; }
    [[nodiscard]] bool isContextInitialized() const { return m_contextInitialized; }

     GLFWwindow* getWindow() const;
    GLFWwindow* getWindow(uint32_t width, uint32_t height, const char* title);
    GLenum setContext();

    static Renderer& getInstance();
    static void freeInstanceIfAny();
private:
    static Renderer* m_instance;
    Renderer();
    ~Renderer();
    GLFWwindow* m_window;
    bool m_initialized;
    bool m_contextInitialized;
    float m_windowWidth;
    float m_windowHeight;
    uint32_t m_mvcRendererId;
};

