#pragma once

#include "PCH.h"
#include <memory>
#include <ShaderSource.h>

namespace shaderCompiler {

class ShaderCompiler {
private:
  int success;
  char infoLog[512];
  static std::shared_ptr<ShaderCompiler> instance;
  ShaderCompiler() = default;

public:
  static std::shared_ptr<ShaderCompiler> getInstance();

  template <GLenum shaderType> GLuint compileShader(const char *sourceCode) {
    GLuint id = glCreateShader(shaderType);
    glShaderSource(id, 1, &sourceCode, NULL);
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &this->success);
    if (!this->success) {
      glGetShaderInfoLog(id, 512, NULL, this->infoLog);
      const char *s;
#define PROCESSVAL(p)                                                          \
  case (p):                                                                    \
    s = #p;
      switch (shaderType) {
        PROCESSVAL(GL_VERTEX_SHADER);
        PROCESSVAL(GL_FRAGMENT_SHADER);
      }
#undef PROCESSVAL
      std::cout << "ERROR::SHADER::" << s << "::COMPILATION_FAILED\n"
                << this->infoLog << "\n";
    }

    return id;
  };

  GLuint compileShader(const shader::ShaderSource& source) {
    GLuint id = glCreateShader(source.getShaderType());
    const char* sourceCode = source.getSourceCode();
    GLenum sourcetype = source.getShaderType();
    glShaderSource(id, 1, &sourceCode, NULL);
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &this->success);
    if (!this->success) {
      glGetShaderInfoLog(id, 512, NULL, this->infoLog);
      const char *s;
#define PROCESSVAL(p)                                                          \
  case (p):                                                                    \
    s = #p;
      switch (source.getShaderType()) {
        PROCESSVAL(GL_VERTEX_SHADER);
        PROCESSVAL(GL_FRAGMENT_SHADER);
      }
#undef PROCESSVAL
      std::cout << "ERROR::SHADER::" << s << "::COMPILATION_FAILED\n"
                << this->infoLog << "\n";
    }

    return id;
  }
};
} // namespace shaderCompiler
