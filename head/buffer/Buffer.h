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
  GLuint stride;
  GLenum bufferType;
  std::vector<buffer::BufferAttribute> attributes;

public:
  Buffer(const GLenum &bufferType);
  /**
   * @brief Binds the buffer to its slot
   * 
   */
  void bind() override;

  /**
   * @brief Unbinds the buffer from its slot
   * 
   */
  void unbind() override;

  /**
   * @brief Initializes the buffer and sets the layout, doesnt need to be called by the user
   * 
   */
  void initialize() override;

  /**
   * @brief Loads the provided data into the buffer on the GPU
   * 
   * @tparam T Data typy of the data
   * @tparam size Size of the block of memory
   * @param data The block of memory to be copied
   * @param usage The usage on the GPU later
   */
  template <typename T, size_t size>
  void loadData(const std::array<T, size> &data, GLenum usage) {
    bindWithoutLoading();
    glBufferData(this->bufferType, sizeof(data), data.data(), usage);
  };

  /**
   * @brief Adds an attribute to the layout of the Buffer
   * 
   * @param attribute The attribute to add
   */
  void addAttribute(const buffer::BufferAttribute &attribute);

private:
  void setLayout();
  void bindWithoutLoading();
};
} // namespace buffer
