#pragma once

#include "Initializable.h"
#include "PCH.h"
#include "Shader.h"

namespace shaderProgramLinker
{
  class ShaderProgramLinker;
}

namespace shader {
class ShaderProgram : Initializable{
friend class shaderProgramLinker::ShaderProgramLinker;

private:
  int id = 0;
  std::vector<shader::Shader> shaders;
  void initialize() override;
  void linkProgram();

public:
  ShaderProgram();
  void addShader(const shader::Shader& shader);
  GLuint getProgramID();
  void use();
};
} // namespace shader