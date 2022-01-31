#pragma once

#include "PCH.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include <cstddef>
#include <memory>

namespace shaderProgramLinker {
class ShaderProgramLinker {
private:
  int success;
  char infoLog[512];
  static std::shared_ptr<ShaderProgramLinker> instance;

public:
  static std::shared_ptr<ShaderProgramLinker> getInstance();

  void linkProgram(shader::ShaderProgram* program, std::vector<shader::Shader>& shaders);
};
} // namespace shaderProgramLinker