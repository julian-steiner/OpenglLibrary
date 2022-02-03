#pragma once

#include "shader/Shader.h"
#include "shader/ShaderCompiler.h"

namespace shader {
class FragmentShader : public shader::Shader {
public:
  FragmentShader(const char *sourceCode) : shader::Shader(GL_FRAGMENT_SHADER, sourceCode) {};
};
} // namespace shader