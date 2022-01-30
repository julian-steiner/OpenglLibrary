#include "Shader.h"

GLuint shader::Shader::getShaderID() { return this->id; }

void shader::Shader::deleteShader() { glDeleteShader(this->getShaderID()); }