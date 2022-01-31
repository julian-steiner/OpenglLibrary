#pragma once

#include "shader/Shader.h"
#include "shader/ShaderCompiler.h"

namespace shader {
class FragmentShader : public shader::Shader {
public:
  FragmentShader(const char *sourceCode);
};
} // namespace shader