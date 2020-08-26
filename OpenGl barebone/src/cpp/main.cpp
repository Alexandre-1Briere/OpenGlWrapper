#include <window.h>

#include <iostream>

int main(void)
{
    window windowController;
    GLFWwindow* window;
    if (!glfwInit())
        return -1;
    
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        LogMessage::critical("GlewInit failed");
    }

    windowController.start();
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        windowController.update();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    windowController.end();
    glfwTerminate();
    return 0;
}