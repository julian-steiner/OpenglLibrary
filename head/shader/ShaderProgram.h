#pragma once

#include "Bindable.h"
#include "Initializable.h"
#include "PCH.h"
#include "shader/Shader.h"

namespace shaderProgramLinker
{
  class ShaderProgramLinker;
}

namespace shader {
class ShaderProgram : Initializable, Bindable{
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
  void bind() override;
  void unbind() override;
};
} // namespace shader