#pragma once

#include "Shader.h"
#include "ShaderCompiler.h"

namespace shader {
class VertexShader : public shader::Shader {
public:
  VertexShader(const char *sourceCode);
};
} // namespace shader