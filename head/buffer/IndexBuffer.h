#pragma once

#include "buffer/Buffer.h"

namespace buffer {
class IndexBuffer : public buffer::Buffer {
public:
  IndexBuffer() : buffer::Buffer(GL_ELEMENT_ARRAY_BUFFER) {}
};
} // namespace buffer