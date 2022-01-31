#include "VertexShader.h"
#include "Shader.h"
#include "ShaderCompiler.h"

shader::VertexShader::VertexShader(const char *sourceCode) : shader::Shader(GL_VERTEX_SHADER, sourceCode) {
  compile();
}