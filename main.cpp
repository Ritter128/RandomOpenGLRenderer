#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

const char* vertexShader = R"(
#version 330 core
layout(location = 0) in vec2 aPosition;

void main()
{
    gl_Position = vec4(aPosition, 0.0, 1.0);
}

)";

const char* fragShader = R"(
#version 330 core

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
)";

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
    {
        printf("Failed to load GLFW\n");
        return -1;
    }

    /* Set up profile and OpenGL version */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        printf("Could create window\n");
        glfwTerminate();
        return -1; 
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGL())
    {
        printf("Could not load GLAD\n");
        glfwTerminate();
        return -1;
    }

    /* Rendering code */

    float vertices[] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    glViewport(0, 0, 600, 400);

    /* Vertex buffer */
    unsigned int vertexBufferID;
    glGenBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    /* Vertex attributes */
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* Shaders */
    
    /* Vertex Shader */
    unsigned int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID, 1, &vertexShader, NULL);
    glCompileShader(vertexShaderID);

    int compileStatusDeVertex;
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &compileStatusDeVertex);

    if (compileStatusDeVertex == GL_FALSE)
    {
        printf("[VERTEX SHADER ERROR]");

        GLsizei infoLength;

        glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLength);

        char* infoLog = (char*)alloca(infoLength * sizeof(char));

        glGetShaderInfoLog(vertexShaderID, infoLength, &infoLength, infoLog);

        std::cout << infoLog << "\n";
    }

    /* Fragment Shader */

    unsigned int fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShaderID, 1, &fragShader, NULL);
    glCompileShader(fragShaderID);

    int compileStatusDeFragment;
    glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &compileStatusDeFragment);

    if (compileStatusDeFragment == GL_FALSE)
    {
        printf("[FRAGMENT SHADER ERROR]");

        GLsizei infoLength;

        glGetShaderiv(fragShaderID, GL_INFO_LOG_LENGTH, &infoLength);

        char* infoLog = (char*)alloca(infoLength * sizeof(char));

        glGetShaderInfoLog(fragShaderID, infoLength, &infoLength, infoLog);

        std::cout << infoLog << "\n";
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShaderID);
    glAttachShader(shaderProgram, fragShaderID);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragShaderID);
        
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        //glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

        glUseProgram(shaderProgram);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shaderProgram);
    glDeleteBuffers(1, &vertexBufferID);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}