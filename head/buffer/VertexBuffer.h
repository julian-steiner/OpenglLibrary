#pragma once

#include "Buffer.h"

namespace buffer {
class VertexBuffer : public buffer::Buffer {
public:
  VertexBuffer() : buffer::Buffer(GL_ARRAY_BUFFER){};
};
} // namespace buffer