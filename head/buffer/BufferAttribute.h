#pragma once

#include "PCH.hpp"

namespace buffer {
class BufferAttribute {
private:
    GLenum type;
    GLint size;
public:
    BufferAttribute (GLenum type, GLint size) : type(type), size(size) {}
    GLenum getType() const {return type;}
    GLint getSize() const {return size;}
};
} // namespace buffer