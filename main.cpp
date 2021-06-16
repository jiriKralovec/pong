#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "source/util/logger.h"
#include "source/renderer.h"
#include "source/input.h"
#include "source/shader.h"

#include "source/rectangle.h"

int terminate(int status)
{
    Renderer::freeInstanceIfAny();
    InputCtrl::freeInstanceIfAny();
    return status;
}

int main() {

    if(!Renderer::getInstance().isInitialized())
        return terminate(-1);

    Renderer::getInstance().getWindow(960, 540, "Pong!");
    if(!Renderer::getInstance().isWindowInitialized())
        return terminate(-2);

    Renderer::getInstance().setContext();
    if(!Renderer::getInstance().isContextInitialized())
        return terminate(-3);

    Rectangle rectangle(0.5f, 0.5f, 0.5f, 0.5f);

    Shader shader;
    Renderer::getInstance().BindMvp(shader);

    while(!glfwWindowShouldClose(Renderer::getInstance().getWindow()))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        rectangle.Draw();

        glfwSwapBuffers(Renderer::getInstance().getWindow());
        glfwPollEvents();
    }

    return terminate(0);

}
