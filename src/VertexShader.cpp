#include "VertexShader.h"
#include "ShaderCompiler.h"

shader::VertexShader::VertexShader(const char *sourceCode) {
  this->compiler = shaderCompiler::ShaderCompiler();
  this->id = this->compiler.compileShader<GL_VERTEX_SHADER>(sourceCode);
}