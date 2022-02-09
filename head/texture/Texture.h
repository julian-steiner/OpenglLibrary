#pragma once

#include "Bindable.h"
#include "Initializable.h"
#include "PCH.h"
#include <string>

#include "stb_image.h"

namespace texture
{
    class Texture : public Bindable, Initializable
    {
    private:
        int width, height, nrChannels;
        unsigned char* data;
        void initialize() override;
        void loadTexture(const std::string& filepath);
        GLenum textureType;
        GLenum textureFormat;
        GLenum slot;

    public:
        Texture(const std::string& filepath, GLenum textureType);
        void bind() override;
        void unbind() override;
        void setSlot(unsigned int slot);
    };
}