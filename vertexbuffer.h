#include <glad/glad.h>

class VertexBuffer 
{
public:
    VertexBuffer(const float* data, unsigned int size);
    ~VertexBuffer();

    void Bind();
    void Unbind();

    unsigned int GetRendererID();
private:
    unsigned int m_RendererID;
};