#include "VertexShader.h"
#include "ShaderCompiler.h"

shader::VertexShader::VertexShader(const char *sourceCode) {
  this->id = shaderCompiler::ShaderCompiler::getInstance()
                 ->compileShader<GL_VERTEX_SHADER>(sourceCode);
}