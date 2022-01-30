#include "FragmentShader.h"
#include "ShaderCompiler.h"

shader::FragmentShader::FragmentShader(const char *sourceCode) {
  this->compiler = shaderCompiler::ShaderCompiler();
  this->id = this->compiler.compileShader<GL_FRAGMENT_SHADER>(sourceCode);
}