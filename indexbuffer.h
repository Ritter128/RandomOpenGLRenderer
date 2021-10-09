#pragma once
#include <glad/glad.h>

class IndexBuffer 
{
public:
    IndexBuffer(const unsigned int* indices, unsigned int size, unsigned int count);
    ~IndexBuffer();

    unsigned int GetCount();

    void Bind();
    void Unbind();

    unsigned int GetRendererID();
private:
    unsigned int m_RendererID;
    unsigned int m_Count;
};