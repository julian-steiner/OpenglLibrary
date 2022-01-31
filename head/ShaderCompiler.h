#pragma once

#include "PCH.h"
#include "Shader.h"
#include <memory>

namespace shaderCompiler {

class ShaderCompiler {
private:
  int success;
  char infoLog[512];
  static std::shared_ptr<ShaderCompiler> instance;
  ShaderCompiler() = default;

public:
  static std::shared_ptr<ShaderCompiler> getInstance();

  void compileShader(shader::Shader *shader);
};
} // namespace shaderCompiler
