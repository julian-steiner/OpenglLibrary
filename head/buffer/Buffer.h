#pragma once

#include "Bindable.h"
#include "Initializable.h"
#include "PCH.h"
#include "buffer/BufferAttribute.h"
#include <array>
#include <cstddef>
#include <vector>

namespace buffer {
class Buffer : public Bindable, Initializable {
private:
  GLuint id;
  GLuint stride;
  GLenum bufferType;
  std::vector<buffer::BufferAttribute> attributes;

public:
  Buffer(const GLenum &bufferType);
  void bind() override;
  void unbind() override;
  void initialize() override;

  template <typename T, size_t size>
  void loadData(const std::array<T, size> &data, GLenum usage) {
    bindWithoutLoading();
    glBufferData(this->bufferType, sizeof(data), data.data(), usage);
  };
  void addAttribute(const buffer::BufferAttribute &attribute);

private:
  void setLayout();
  void bindWithoutLoading();
};
} // namespace buffer
