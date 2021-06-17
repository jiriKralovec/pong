#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "source/util/logger.h"
#include "source/renderer.h"
#include "source/object-store.h"
#include "source/input.h"

#include "source/triangle.h"

int terminate(int status)
{
    Renderer::freeInstanceIfAny();
    ObjectStore::freeInstanceIfAny();
    return status;
}

int main() {

    if(!glfwInit())
    {
        LOG("GLFW failed to initialize");
        return -1;
    }

    if(!Renderer::getInstance().CreateWindowIfNotExists(960, 540, "Pong!"))
        return terminate(-3);

    Renderer::getInstance().GetMainShaderInstance().Bind();
    Renderer::getInstance().SetRenderingContext();

    Triangle a({50.0f, 50.0f}, { 0.0f, 0.0f });
    Triangle b({50.0f, 50.0f}, { 150.0f, 0.0f });
    Triangle c({50.0f, 50.0f}, { 300.0f, 0.0f });

    while(!Renderer::getInstance().ShouldCurrentWindowClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        ObjectStore::getInstance().RunBatchUpdate();
        ObjectStore::getInstance().RunBatchDraw();

        glfwSwapBuffers(&Renderer::getInstance().GetCurrentWindowInstance());
        glfwPollEvents();
    }

    terminate(0);

    return 0;

}
