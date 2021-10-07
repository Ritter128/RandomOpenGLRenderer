#include "shaders.h"
#include <glad/glad.h>
#include <iostream>

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
        }

        GLsizei infoLength;

        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLength);

        char* infoLog = (char*)alloca(infoLength * sizeof(char));

        glGetShaderInfoLog(shaderID, infoLength, &infoLength, infoLog);

        std::cout << infoLog << "\n";
    }

    return shaderID;
}