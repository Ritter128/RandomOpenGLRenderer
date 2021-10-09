#include "indexbuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int size, unsigned int count)
{
    m_Count = count;
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID); // CHKERR
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

unsigned int IndexBuffer::GetCount()
{
    return m_Count;
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void IndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void IndexBuffer::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::GetRendererID()
{
    return m_RendererID;
}