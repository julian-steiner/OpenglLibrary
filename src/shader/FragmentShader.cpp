#include "shader/FragmentShader.h"
#include "shader/Shader.h"
#include "shader/ShaderCompiler.h"

shader::FragmentShader::FragmentShader(const char *sourceCode) : shader::Shader(GL_FRAGMENT_SHADER, sourceCode){
  compile();
}