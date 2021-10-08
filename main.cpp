#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "shaders.h"

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
        //inFile >> item;
        std::cout << "-> " << item << "\n";
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
    window = glfwCreateWindow(600, 400, "Hello World", NULL, NULL);
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

    float vertices[] = {
        -0.5f, -0.5f,  0.5f, //0
        -0.5f,  0.5f,  0.5f, //1
         0.5f, -0.5f,  0.5f, //2
         0.5f,  0.5f,  0.5f, //3
         0.5f, -0.5f, -0.5f, //4
         0.5f,  0.5f, -0.5f, //5
        -0.5f, -0.5f, -0.5f, //6
        -0.5f,  0.5f, -0.5f, //7
    };

    unsigned int indices[] = {
        0, 1, 2,
        1, 3, 2,
        3, 2, 4,      
        4, 3, 5,
        0, 1, 6,
        6, 1, 7,
        4, 5, 6,
        6, 7, 5,
        1, 3, 7,      
        7, 3, 5,
        0, 2, 6,
        6, 2, 4
    };

    glViewport(0, 0, 600, 400);

    /* Vertex Array */
    unsigned int vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);

    /* Vertex buffer */
    unsigned int vertexBufferID;
    glGenBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    /* Index buffer */
    unsigned int indexBufferID;
    glGenBuffers(1, &indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID); // CHKERR
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    /* Vertex attributes */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(0);
    
    /* Shaders */
    std::string vsSource = ReadFile("vertShader.glsl");
    std::string fsSource = ReadFile("fragShader.glsl");

    unsigned int vertexShaderID = CompileShader(vsSource, GL_VERTEX_SHADER);
    unsigned int fragShaderID = CompileShader(fsSource, GL_FRAGMENT_SHADER);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShaderID);
    glAttachShader(shaderProgram, fragShaderID);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragShaderID);
 
    glEnable(GL_DEPTH_TEST);
        
    float rot = 0.0f;
    cubePos.z = -6.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        glUseProgram(shaderProgram);

        /* Matrices */
        glm::mat4 modelMatrix = glm::mat4(1.0f);
        glm::mat4 modelTranslationMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, cubePos.z));
        glm::mat4 modelRotationMatrix = glm::rotate(modelMatrix, glm::radians(cubeRotX), glm::vec3(0.0f, 1.0f, 0.0f));
        modelMatrix = modelTranslationMatrix * modelRotationMatrix;
        ///glm::mat4 viewMatrix = glm::mat4(1.0f);
        //glm::mat4 translationViewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, cubePos.z));
        //viewMatrix = glm::rotate(
            //viewMatrix, camRotX, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::translate(viewMatrix, glm::vec3(0.0f, camRotX, 0.0f));
        glm::mat4 projMatrix = glm::mat4(1.0f);
        projMatrix = glm::perspective(glm::radians(90.0f), (float)(600/400), 0.1f, 100.0f);

        /* Uniforms */
        int locModelMatrix = glGetUniformLocation(shaderProgram, "uModelMatrix");
        glUniformMatrix4fv(locModelMatrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
        //int locViewMatrix = glGetUniformLocation(shaderProgram, "uViewMatrix");
        //glUniformMatrix4fv(locViewMatrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));
        int locProjMatrix = glGetUniformLocation(shaderProgram, "uProjMatrix");
        glUniformMatrix4fv(locProjMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix)); 
        
        //std::cout << "CAMERA POSITION Z: " << cubePos.z << "\n";
        //std::cout << "CUBE ROT X: " << cubeRotX << "\n";

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

            /* Swap front and back buffers */

        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shaderProgram);
    glDeleteBuffers(1, &vertexBufferID);
    glDeleteBuffers(1, &indexBufferID);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}