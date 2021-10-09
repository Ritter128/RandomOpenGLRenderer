#include "texture.h"
#include <iostream>

Texture::Texture(const std::string fileName, int level)
{
    m_Level = level;
    int w, h, nrChannels;
    unsigned char* imageFile = stbi_load("Textures/dirt.jpg", &w, &h, &nrChannels, 4);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if(!imageFile)
    {
        std::cout << "Cannot load image\n";
    }
    else
    {
        glGenTextures(1, &m_RendererID);
        glBindTexture(GL_TEXTURE_2D, m_RendererID);
        glTexImage2D(GL_TEXTURE_2D, m_Level, GL_RGBA, w, h, 0, 
        GL_RGBA, GL_UNSIGNED_BYTE, imageFile);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    } 
    stbi_image_free(imageFile);
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::Unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture::GetRendererID()
{
    return m_RendererID;
}