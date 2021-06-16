#include "renderer.h"

GLFWwindow* Renderer::getWindow() const {
    if(m_window != nullptr)
        glfwMakeContextCurrent(m_window);
    return m_window;
}
GLFWwindow* Renderer::getWindow(const uint32_t width, const uint32_t height, const char* title)
{
    if(m_window == nullptr)
    {
        m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        glfwMakeContextCurrent(m_window);
    }
    return m_window;
}
Renderer& Renderer::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new Renderer();
    }
    return *m_instance;
}
void Renderer::freeInstanceIfAny() {
    delete m_instance;
    m_instance = nullptr;
}
Renderer::Renderer() : m_window(nullptr)
{
    /** Initialize GLFW */
    m_initialized = glfwInit() == GL_TRUE;
    if(!m_initialized)
        LOG("Failed to initialize GLFW context");
}
Renderer::~Renderer()
{
    if(isInitialized())
        glfwTerminate();
}

Renderer* Renderer::m_instance = nullptr;
