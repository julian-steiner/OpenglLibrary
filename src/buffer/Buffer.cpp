#include "buffer/Buffer.h"
#include "buffer/BufferAttribute.h"
#include <vector>

buffer::Buffer::Buffer(const GLenum &bufferType)
    : bufferType(bufferType), stride(0),
      attributes(std::vector<buffer::BufferAttribute>()) {
  glGenBuffers(1, &this->id);
}

void buffer::Buffer::initialize() {
  if (!isInitialized()) {
    setLayout();
    initialized = true;
  }
}

void buffer::Buffer::bindWithoutLoading() {
  glBindBuffer(this->bufferType, this->id);
}

void buffer::Buffer::bind() {
  initialize();
  glBindBuffer(this->bufferType, this->id);
}

void buffer::Buffer::unbind() { glBindBuffer(this->bufferType, 0); }

void buffer::Buffer::addAttribute(const buffer::BufferAttribute &attribute) {
  stride += attribute.getSize() * sizeof(attribute.getType());
  attributes.push_back(attribute);
}

void buffer::Buffer::setLayout() {
  int *offset = 0;

  bindWithoutLoading();

  for (unsigned int i = 0; i < attributes.size(); i++) {
    const buffer::BufferAttribute &attribute = attributes.at(i);
    glVertexAttribPointer(i, attribute.getSize(), attribute.getType(), GL_FALSE,
                          stride, (const void *)offset);
    glEnableVertexAttribArray(i);
    offset += attribute.getSize() * sizeof(attribute.getType());
  }
}
