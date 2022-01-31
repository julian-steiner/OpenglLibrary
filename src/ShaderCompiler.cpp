#include "ShaderCompiler.h"
#include <memory>

std::shared_ptr<shaderCompiler::ShaderCompiler>
    shaderCompiler::ShaderCompiler::instance = 0;

std::shared_ptr<shaderCompiler::ShaderCompiler>
shaderCompiler::ShaderCompiler::getInstance() {
  if (ShaderCompiler::instance == nullptr) {
    ShaderCompiler::instance = std::make_shared<shaderCompiler::ShaderCompiler>(
        shaderCompiler::ShaderCompiler());
  }
  return ShaderCompiler::instance;
}

void shaderCompiler::ShaderCompiler::compileShader(shader::Shader *shader) {
  shader->id = glCreateShader(shader->getShaderType());
  const char *sourceCode = shader->getSourceCode();
  glShaderSource(shader->id, 1, &shader->sourceCode, NULL);
  glCompileShader(shader->id);
  glGetShaderiv(shader->id, GL_COMPILE_STATUS, &this->success);
  if (!this->success) {
    glGetShaderInfoLog(shader->id, 512, NULL, this->infoLog);
    const char *s;
#define PROCESSVAL(p)                                                          \
  case (p):                                                                    \
    s = #p;
    switch (shader->getShaderType()) {
      PROCESSVAL(GL_VERTEX_SHADER);
      PROCESSVAL(GL_FRAGMENT_SHADER);
    }
#undef PROCESSVAL
    std::cout << "ERROR::SHADER::" << s << "::COMPILATION_FAILED\n"
              << this->infoLog << "\n";
  }
};