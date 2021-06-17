#include "renderer.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


Renderer* Renderer::m_instance = nullptr;

void Renderer::Draw(const VertexArrayObject &vao, const IndexBuffer &vbo) const
{
    vao.Bind();
    vbo.Bind();
    glDrawElements(
            GL_TRIANGLES,
            vbo.IndexCount(),
            GL_UNSIGNED_INT,
            (void*)0
    );
    VertexArrayObject::Unbind();
    IndexBuffer::Unbind();
}
void Renderer::Draw(const VertexArrayObject& vao) const
{
    vao.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    VertexArrayObject::Unbind();
}
void Renderer::Draw(const VertexBuffer* vb) const
{
    vb->Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, vb->VertexCount()));
    vb->Unbind();
}
void Renderer::SetRenderingContext() const
{
    if(m_shader == nullptr)
    {
        LOG("Failed to set rendering context - no main shader attached");
        return;
    }

    m_shader->Bind();

    auto projection = glm::ortho(0.0f, static_cast<float>(m_windowWidth), static_cast<float>(m_windowHeight), 0.0f, -1.0f, 1.0f);

    GLuint projectionUniformLocation = glGetUniformLocation(m_shader->GetRendererId(), "uProjection");

    glUniformMatrix4fv(projectionUniformLocation, 1, GL_FALSE, glm::value_ptr(projection));

}
const Shader& Renderer::GetMainShaderInstance()
{
    if(m_shader == nullptr)
        m_shader = new Shader("shaders/basic.vertex.glsl", "shaders/basic.fragment.glsl");
    return *m_shader;
}
bool Renderer::ShouldCurrentWindowClose() const
{
    if(m_window == nullptr)
        return true;
    return glfwWindowShouldClose(m_window);
}
int Renderer::CreateWindowIfNotExists(uint32_t width, uint32_t height, const char *title) {

    if(m_window != nullptr)
    {
        LOG("Error while creating new GLFW window - window is already created!");
        return -1;
    }

    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if(m_window == nullptr)
    {
        LOG("Error while creating new GLFW window - window failed to initialize");
        return -2;
    }

    m_windowWidth = width;
    m_windowHeight = height;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);

    GLenum glewInitStatus = glewInit();
    if(glewInitStatus != GLEW_OK)
    {
        std::cout << "GLEW failed to initialize: " << glewGetErrorString(glewInitStatus) << std::endl;
        return -2;
    }

    return 1;

}
Renderer& Renderer::getInstance() {
    if(m_instance == nullptr)
        m_instance = new Renderer();
    return *m_instance;
}
void Renderer::freeInstanceIfAny() {
    if(m_instance != nullptr)
        delete m_instance;
    m_instance = nullptr;
}
Renderer::Renderer(): m_windowWidth(0), m_windowHeight(0), m_window(nullptr), m_shader(nullptr) { }
Renderer::~Renderer() {

    if(m_shader != nullptr)
    {
        m_shader->Unbind();
        delete m_shader;
    }
    m_shader = nullptr;

    if(m_window != nullptr)
        glfwDestroyWindow(m_window);

    glfwTerminate();

}