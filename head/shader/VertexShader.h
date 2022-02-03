#pragma once

#include "shader/Shader.h"
#include "shader/ShaderCompiler.h"

namespace shader {
class VertexShader : public shader::Shader {
public:
  VertexShader(const char *sourceCode) : shader::Shader(GL_VERTEX_SHADER, sourceCode) {};
};
} // namespace shader