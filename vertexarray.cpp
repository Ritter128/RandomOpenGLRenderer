#include "vertexarray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
    glBindVertexArray(m_RendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::LinkVertexAttrib(VertexBuffer& vertexBuffer)
{
    vertexBuffer.Bind();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (const void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    vertexBuffer.Unbind();
}

void VertexArray::Bind()
{
    glBindVertexArray(m_RendererID);
}

void VertexArray::Unbind()
{
    glBindVertexArray(0);
}

unsigned int VertexArray::GetRendererID()
{
    return m_RendererID;
}