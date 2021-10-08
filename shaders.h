#pragma once
#include <string>
#include <glm/glm.hpp>

unsigned int CompileShader(const std::string& src, unsigned int type);

class Shader 
{
public:
    Shader(unsigned int vertexShaderID, unsigned int fragmentShaderID);
    ~Shader();

    void Bind();
    void Unbind();

    void SetUniformMatrix4FV(const std::string name, const glm::mat4& matrix);
    void SetUniformInt(const std::string name, int value);

    unsigned int GetRendererID();
private:
    unsigned int m_RendererID;
};