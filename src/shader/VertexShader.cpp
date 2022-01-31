#include "shader/VertexShader.h"
#include "shader/Shader.h"
#include "shader/ShaderCompiler.h"

shader::VertexShader::VertexShader(const char *sourceCode) : shader::Shader(GL_VERTEX_SHADER, sourceCode) {
  compile();
}