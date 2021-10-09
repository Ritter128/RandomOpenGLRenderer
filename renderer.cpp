#include "renderer.h"

Renderer::Renderer(VertexArray& vertexArray, IndexBuffer& indexBuffer, Texture& texture, Shader program)
{
    /* Render here */
    vertexArray.Bind();
    indexBuffer.Bind();
    texture.Bind();
    program.Bind();
    
    //std::cout << "CAMERA POSITION Z: " << cubePos.z << "\n";
    //std::cout << "CUBE ROT X: " << cubeRotX << "\n";
    glDrawElements(GL_TRIANGLES, indexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
}