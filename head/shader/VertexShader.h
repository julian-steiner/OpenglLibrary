#pragma once

#include "shader/Shader.h"
#include "shader/ShaderCompiler.h"

namespace shader {
class VertexShader : public shader::Shader {
public:
  VertexShader(const char *sourceCode);
};
} // namespace shader