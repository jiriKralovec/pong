#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "source/util/logger.h"
#include "source/renderer.h"
#include "source/input.h"

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

    while(!glfwWindowShouldClose(Renderer::getInstance().getWindow()))
    {
        glfwSwapBuffers(Renderer::getInstance().getWindow());
        glfwPollEvents();
    }

    return terminate(0);

}
