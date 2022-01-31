#include "FragmentShader.h"
#include "Shader.h"
#include "ShaderCompiler.h"

shader::FragmentShader::FragmentShader(const char *sourceCode) : shader::Shader(GL_FRAGMENT_SHADER, sourceCode){
  compile();
}