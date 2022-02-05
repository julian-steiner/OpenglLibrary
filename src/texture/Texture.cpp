#include "texture/Texture.h"

texture::Texture::Texture(const std::string &filepath, GLenum textureType) : slot(GL_TEXTURE0), textureType(textureType) {
  loadTexture(filepath);
  glGenTextures(1, &this->rendererID);

  glBindTexture(textureType, this->rendererID);

  glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(textureType, GL_TEXTURE_WRAP_R, GL_REPEAT);

  glTexImage2D(textureType, 0, GL_RGBA, width, height, 0, this->textureFormat,
               GL_UNSIGNED_BYTE, data);

  glGenerateMipmap(textureType);
  stbi_image_free(data);

  unbind();

  initialize();
}

void texture::Texture::initialize() {
  if (!this->isInitialized()) {
    initialized = true;
  }
}

void texture::Texture::loadTexture(const std::string& filepath) {
  stbi_set_flip_vertically_on_load(true);
  data = stbi_load(filepath.c_str(), &this->width, &this->height,
                   &this->nrChannels, 0);

  switch (this->nrChannels) {
  case 3:
    this->textureFormat = GL_RGB;
  case 4:
    this->textureFormat = GL_RGBA;
  default:
    this->textureFormat = GL_RGB;
  }
}

void texture::Texture::bind() {
  glActiveTexture(this->slot);
  glBindTexture(this->textureType, this->rendererID);
}

void texture::Texture::unbind() {
  glActiveTexture(this->slot);
  glBindTexture(this->textureType, 0);
}

void texture::Texture::setSlot(unsigned int slot) {
  this->slot = GL_TEXTURE0 + slot;
}