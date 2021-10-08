#include <glad/glad.h>
#include "vertexbuffer.h"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void LinkVertexAttrib(VertexBuffer& vertexBuffer);

    void Bind();
    void Unbind();

    unsigned int GetRendererID();
private:
    unsigned int m_RendererID;
};