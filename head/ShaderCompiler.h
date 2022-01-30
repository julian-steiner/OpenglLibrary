#pragma once

#include "PCH.h"

namespace shaderCompiler {

class ShaderCompiler {
private:
  int success;
  char infoLog[512];

public:
  template <GLenum shaderType> GLuint compileShader(const char *sourceCode) {
    GLuint id = glCreateShader(shaderType);
    glShaderSource(id, 1, &sourceCode, NULL);
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &this->success);
    if (!this->success) {
      glGetShaderInfoLog(id, 512, NULL, this->infoLog);
      std::cout << "ERROR::SHADER::" << shaderType << "::COMPILATION_FAILED\n"
                << this->infoLog << "\n";
    }

    return id;
  };
};
} // namespace shaderCompiler
