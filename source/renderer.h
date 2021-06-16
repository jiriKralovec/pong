#pragma once
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "util/logger.h"

class Renderer
{
public:
    [[nodiscard]] bool isWindowInitialized() const { return m_window != nullptr; }
    [[nodiscard]] bool isInitialized() const { return m_initialized; }
    GLFWwindow* getWindow() const;
    GLFWwindow* getWindow(uint32_t width, uint32_t height, const char* title);
    static Renderer& getInstance();
    static void freeInstance();
private:
    static Renderer* m_instance;
    Renderer();
    ~Renderer();
    GLFWwindow* m_window;
    bool m_initialized;
};

