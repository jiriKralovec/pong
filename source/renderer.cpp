#include "renderer.h"

GLenum Renderer::setContext()
{
    if(m_window == nullptr)
    {
        LOG("Error setting correct context - window does not exist!");
        return GL_FALSE;
    }
    if(m_contextInitialized)
    {
        LOG("Context is already initialized");
        return GL_TRUE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);

    GLenum initStatus = glewInit();

    if(initStatus == GLEW_OK)
    {
        m_contextInitialized = true;
        return GL_TRUE;
    }
    return initStatus;

}
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
Renderer::Renderer() : m_window(nullptr), m_contextInitialized(false)
{
    /** Initialize GLFW */
    m_initialized = glfwInit() == GL_TRUE;
    if(!m_initialized)
        LOG("Failed to initialize GLFW context");
}
Renderer::~Renderer()
{
    if(isInitialized())
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
}

Renderer* Renderer::m_instance = nullptr;
