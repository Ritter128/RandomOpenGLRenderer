#include <stdio.h>
#include <GLFW/glfw3.h>

int main(void)
{
    if (!glfwInit())
    {
        printf("BRUH\n");
    }

    GLFWwindow* window = glfwCreateWindow(
        600, 400, "LEARNCMAKE!", NULL, NULL
    );

    if (!window)
    {
        printf("Could not create window\n");
    }

    glfwMakeContextCurrent(window);

    if (!glfwWindowShouldClose(window))
    {

        //glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}