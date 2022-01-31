#include "Shader.h"
#include "ShaderCompiler.h"

GLuint shader::Shader::getShaderID() { return this->id; }

GLenum shader::Shader::getShaderType() const { return this->shaderType; }

const char *shader::Shader::getSourceCode() const { return this->sourceCode; }

void shader::Shader::deleteShader() { glDeleteShader(this->getShaderID()); }

void shader::Shader::compile() {
  shaderCompiler::ShaderCompiler::getInstance()->compileShader(this);
}

void shader::Shader::initialize() {
  if (isInitialized()) {
    return;
  } else {
    compile();
    initialized = true;
  }
}