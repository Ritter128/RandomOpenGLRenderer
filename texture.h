#include <glad/glad.h>
#include <stb_image.h>
#include <string>

class Texture 
{
public:
    Texture(const std::string fileName, int level);
    ~Texture();

    void Bind();
    void Unbind();


    unsigned int GetRendererID();
private:
    unsigned int m_RendererID;
    int m_Level;
};