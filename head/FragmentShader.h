#pragma once

#include "Shader.h"
#include "ShaderCompiler.h"

namespace shader {
class FragmentShader : public shader::Shader {
public:
  FragmentShader(const char *sourceCode);
};
} // namespace shader