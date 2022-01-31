#include "FragmentShader.h"
#include "ShaderCompiler.h"

shader::FragmentShader::FragmentShader(const char *sourceCode) {
  this->id = shaderCompiler::ShaderCompiler::getInstance()
                 ->compileShader<GL_FRAGMENT_SHADER>(sourceCode);
}