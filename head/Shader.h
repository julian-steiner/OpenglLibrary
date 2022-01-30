#pragma once

#include "PCH.h"
#include "ShaderCompiler.h"

namespace shader {
class Shader {
protected:
  int success;
  GLenum shaderType = 0;
  char infoLog[512];
  const char *sourceCode;
  GLuint id;
  shaderCompiler::ShaderCompiler compiler;

public:
  Shader() = default;
  GLuint getShaderID();
  void deleteShader();
};
} // namespace shader