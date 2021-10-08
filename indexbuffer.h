#pragma once
#include <glad/glad.h>

class IndexBuffer 
{
public:
    IndexBuffer(const unsigned int* indices, unsigned int size);
    ~IndexBuffer();

    void Bind();
    void Unbind();

    unsigned int GetRendererID();
private:
    unsigned int m_RendererID;
};