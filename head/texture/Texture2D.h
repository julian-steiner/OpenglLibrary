#include "texture/Texture.h"

namespace texture
{
    class Texture2D : public texture::Texture
    {
    public:
        Texture2D(const std::string& filepath) : texture::Texture(filepath, GL_TEXTURE_2D) {}
    };
}