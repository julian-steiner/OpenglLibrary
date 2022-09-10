#pragma once

#include "PCH.hpp"
#include "shader/Shader.h"
#include "shader/ShaderProgram.h"
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

  void linkProgram(shader::ShaderProgram* program);
};
} // namespace shaderProgramLinker