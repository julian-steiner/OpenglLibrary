#pragma once

#include "PCH.h"
#include "Shader.h"
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

  //   GLuint linkProgram(shader::Shader vertexShader, shader::Shader
  //   fragmentShader);
  GLuint linkProgram(std::vector<shader::Shader>& shaders);
};
} // namespace shaderProgramLinker