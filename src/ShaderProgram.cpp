#include "ShaderProgram.h"
#include "ShaderProgramLinker.h"

shader::ShaderProgram shader::ShaderProgram::fromShaders(std::vector<shader::Shader> &shaders)
{
    shader::ShaderProgram program;
    program.id = shaderProgramLinker::ShaderProgramLinker::getInstance()->linkProgram(shaders);
    return program;
}

GLuint shader::ShaderProgram::getProgramID()
{
    return this->id;
}