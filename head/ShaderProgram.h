#pragma once

#include "PCH.h"
#include "Shader.h"

namespace shaderProgramLinker
{
  class ShaderProgramLinker;
}

namespace shader {
class ShaderProgram {
friend class shaderProgramLinker::ShaderProgramLinker;

private:
  int id = 0;

public:
  ShaderProgram(std::vector<shader::Shader> &shaders);
  GLuint getProgramID();
  void use();
};
} // namespace shader