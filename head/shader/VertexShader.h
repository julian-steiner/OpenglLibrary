#pragma once

#include "shader/Shader.h"
#include "shader/ShaderCompiler.h"

namespace shader {
class VertexShader : public shader::Shader {
public:
  /**
   * @brief Construct a new Vertex Shader object
   * 
   * @param the source code of the shader
   */
  VertexShader(const char *sourceCode) : shader::Shader(GL_VERTEX_SHADER, sourceCode) {};
};
} // namespace shader