#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "source/util/logger.h"
#include "source/renderer.h"

int terminate(int status)
{
    Renderer::freeInstance();
    return status;
}

int main() {

    if(!Renderer::getInstance().isInitialized())
        return terminate(-1);

    Renderer::getInstance().getWindow(960, 540, "Pong!");
    if(!Renderer::getInstance().isWindowInitialized())
        return terminate(-2);

    while(!glfwWindowShouldClose(Renderer::getInstance().getWindow()))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(Renderer::getInstance().getWindow());
        glfwPollEvents();
    }

    return terminate(0);

}
