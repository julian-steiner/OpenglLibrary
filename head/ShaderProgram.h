#pragma once

#include "PCH.h"
#include "Shader.h"
#include "ShaderProgramLinker.h"

namespace shader {
class ShaderProgram {
private:
  ShaderProgram() = default;
  int id = 0;

public:
  static ShaderProgram fromShaders(std::vector<shader::Shader>& shaders);
  static ShaderProgram fromSourceCodes(const char *vertexShaderSource,
                                       const char *fragmentShaderSource);
  GLuint getProgramID();
};
} // namespace shader