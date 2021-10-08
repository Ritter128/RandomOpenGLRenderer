#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

struct Vertex 
{
    glm::vec3 position;
    glm::vec2 texCoords;
};

class VertexBuffer 
{
public:
    VertexBuffer(const Vertex* data, unsigned int size);
    ~VertexBuffer();

    void Bind();
    void Unbind();

    unsigned int GetRendererID();
private:
    unsigned int m_RendererID;
};