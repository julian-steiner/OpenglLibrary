#pragma once

#include "PCH.h"
#include "ShaderCompiler.h"
#include "ShaderSource.h"
#include <memory>

namespace shader {
class Shader {
protected:
  int success;
  GLenum shaderType = 0;
  char infoLog[512];
  const char *sourceCode;
  GLuint id;

public:
  Shader() = default;
  Shader(const shader::ShaderSource& sourceCode);
  GLuint getShaderID();
  void deleteShader();
};
} // namespace shader