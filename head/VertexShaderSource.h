#pragma once

#include "ShaderSource.h"

namespace shader {
class VertexShaderSource : public ShaderSource {
public:
  VertexShaderSource(const char* sourceCode): shader::ShaderSource(sourceCode, GL_VERTEX_SHADER) {};
};
} // namespace shader