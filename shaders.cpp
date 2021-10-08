#include "shaders.h"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

Shader::Shader(unsigned int vertexShaderID, unsigned int fragmentShaderID)
{
    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, vertexShaderID);
    glAttachShader(m_RendererID, fragmentShaderID);
    glLinkProgram(m_RendererID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

Shader::~Shader()
{
    glDeleteProgram(m_RendererID);
}

void Shader::SetUniformMatrix4FV(const std::string name, const glm::mat4& matrix)
{
    int location = glGetUniformLocation(m_RendererID, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::SetUniformInt(const std::string name, int value)
{
    int location = glGetUniformLocation(m_RendererID, name.c_str());
    glUniform1i(location, value);
}

unsigned int Shader::GetRendererID()
{
    return m_RendererID;
}

void Shader::Bind()
{
    glUseProgram(m_RendererID);
}

void Shader::Unbind()
{
    glUseProgram(0);
}

unsigned int CompileShader(const std::string& src, unsigned int type)
{
    const char* cSource = src.c_str();
    unsigned int shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &cSource, NULL);
    glCompileShader(shaderID);

    int compileStatus;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);

    if (compileStatus == GL_FALSE)
    {
        switch (type)
        {
            case GL_VERTEX_SHADER:
            {
                std::cout << "[VERTEX SHADER ERROR]\n";
                break;
            }
            case GL_FRAGMENT_SHADER:
            {
                std::cout << "[FRAGMENT SHADER ERROR]\n";
                break;
            }
            case GL_GEOMETRY_SHADER:
            {
                std::cout << "[GEOMETRY SHADER ERROR]\n";
                break;
            }
            case GL_COMPUTE_SHADER:
            {
                std::cout << "[COMPUTE SHADER ERROR]\n";
                break;
            }
        }

        GLsizei infoLength;

        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLength);

        char* infoLog = (char*)alloca(infoLength * sizeof(char));

        glGetShaderInfoLog(shaderID, infoLength, &infoLength, infoLog);

        std::cout << infoLog << "\n";
    }

    return shaderID;
}