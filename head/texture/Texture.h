#pragma once

#include "Bindable.h"
#include "Initializable.h"
#include "PCH.hpp"
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

        /**
         * @brief Binds the texture to its slot
         * 
         */
        void bind() override;

        /**
         * @brief Unbinds the texture
         * 
         */
        void unbind() override;

        /**
         * @brief Set the slot of the texture
         * 
         * @param slot 
         */
        void setSlot(unsigned int slot);
    };
}