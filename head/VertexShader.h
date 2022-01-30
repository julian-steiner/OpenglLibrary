#pragma once

#include "Shader.h"
#include "ShaderCompiler.h"

namespace shader {
class VertexShader : public shader::Shader {
public:
  VertexShader() = default;
  VertexShader(const char *sourceCode);
};
} // namespace shader