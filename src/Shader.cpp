#include "Shader.h"
#include "ShaderCompiler.h"
#include "ShaderSource.h"

shader::Shader::Shader(const shader::ShaderSource& sourceCode)
{
    this->id = shaderCompiler::ShaderCompiler::getInstance()->compileShader(sourceCode);
}

GLuint shader::Shader::getShaderID() { return this->id; }

void shader::Shader::deleteShader() { glDeleteShader(this->getShaderID()); }
