#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "renderer.h"

/* GLOBALS */
glm::vec3 cubePos;
float camRotX;
float cubeRotX;

void OnKey(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_W)
    {
        cubePos.z += 0.1f;
    }
    if (key == GLFW_KEY_S)
    {
        cubePos.z -= 0.1f;
    }
    
    if (key == GLFW_KEY_A)
    {
        camRotX += 0.1f;
    }
    if (key == GLFW_KEY_D)
    {
        camRotX -= 0.1f;
    }

    if (key == GLFW_KEY_E)
    {
        cubeRotX += 5.0f;
    }
    if (key == GLFW_KEY_Q)
    {
        cubeRotX -= 5.0f;
    }
}

const std::string ReadFile(std::string name)
{
    std::ifstream inFile;
    inFile.open(name);
    std::stringstream contents;

    std::string item;

    if (inFile.fail())
    {
        return "Failed to read file";
    }

    while(getline(inFile, item))
    {
        contents << item << "\n";
    }
    

    return contents.str();
}

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
    window = glfwCreateWindow(600, 400, "Seggs Engine 420", NULL, NULL);
    if (!window)
    {
        printf("Could create window\n");
        glfwTerminate();
        return -1; 
    }

    /* Callbacks */
    glfwSetKeyCallback(window, OnKey);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGL())
    {
        printf("Could not load GLAD\n");
        glfwTerminate();
        return -1;
    }

    /* Rendering code */

    Vertex vertices[] = {
        glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(4.0f, 4.0f), //0
        glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(4.0f, 0.0f), //1
        glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f), //2
        glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(0.0f, 4.0f), //3
    };

    unsigned int indices[] = {
        0, 1, 2,
        1, 3, 2,            
    };

    glViewport(0, 0, 600, 400);

    /* Texture */
    Texture texture("Textures/dirt.jpg", 0);

    /* Vertex Array */
    VertexArray vertexArray;

    /* Buffers */
    VertexBuffer vertexBuffer(vertices, sizeof(vertices));
    IndexBuffer indexBuffer(indices, sizeof(indices), 6);

    /* Vertex attributes */
    vertexArray.LinkVertexAttrib(vertexBuffer);
    
    /* Shaders */
    std::string vsSource = ReadFile("Shaders/vertShader.glsl");
    std::string fsSource = ReadFile("Shaders/fragShader.glsl");

    unsigned int vertexShaderID = CompileShader(vsSource, GL_VERTEX_SHADER);
    unsigned int fragShaderID = CompileShader(fsSource, GL_FRAGMENT_SHADER);

    Shader shaderProgram(vertexShaderID, fragShaderID);
 
    glEnable(GL_DEPTH_TEST);
        
    float rot = 0.0f;
    cubePos.z = -6.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        shaderProgram.Bind();

        /* Matrices */
        glm::mat4 modelMatrix = glm::mat4(1.0f);
        glm::mat4 modelTranslationMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, cubePos.z));
        glm::mat4 modelRotationMatrix = glm::rotate(modelMatrix, glm::radians(cubeRotX), glm::vec3(0.0f, 1.0f, 0.0f));
        modelMatrix = modelTranslationMatrix * modelRotationMatrix;
        glm::mat4 projMatrix = glm::mat4(1.0f);
        projMatrix = glm::perspective(glm::radians(90.0f), (float)(600/400), 0.1f, 100.0f);

        /* Uniforms */
        shaderProgram.SetUniformMatrix4FV("uModelMatrix", modelMatrix);
        shaderProgram.SetUniformMatrix4FV("uProjMatrix", projMatrix);
        shaderProgram.SetUniformInt("uTexSampler", 0);
        
        //std::cout << "CAMERA POSITION Z: " << cubePos.z << "\n";
        //std::cout << "CUBE ROT X: " << cubeRotX << "\n";

        Renderer renderer(vertexArray, indexBuffer, texture, shaderProgram);

        /* Swap front and back buffers */

        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(0);
}