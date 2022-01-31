#include "ShaderProgram.h"
#include "Shader.h"
#include "ShaderProgramLinker.h"
#include <vector>

shader::ShaderProgram::ShaderProgram(std::vector<shader::Shader>& shaders)
{
    this->id = glCreateProgram();
    shaderProgramLinker::ShaderProgramLinker::getInstance()->linkProgram(this, shaders);
}

GLuint shader::ShaderProgram::getProgramID()
{
    return this->id;
}

void shader::ShaderProgram::use()
{
    glUseProgram(this->id);
}