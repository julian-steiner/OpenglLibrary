#include "ShaderProgram.h"
#include "Shader.h"
#include "ShaderProgramLinker.h"
#include <vector>

shader::ShaderProgram::ShaderProgram() {
  this->id = glCreateProgram();
  this->shaders = std::vector<shader::Shader>();
}

GLuint shader::ShaderProgram::getProgramID() { return this->id; }

void shader::ShaderProgram::use() {
  initialize();
  glUseProgram(this->id);
}

void shader::ShaderProgram::addShader(const shader::Shader &shader) {
  this->shaders.push_back(shader);
}

void shader::ShaderProgram::linkProgram() {
  shaderProgramLinker::ShaderProgramLinker::getInstance()->linkProgram(this);
}

void shader::ShaderProgram::initialize() {
  if (isInitialized()) {
    return;
  } else {
    linkProgram();
    initialized = true;
  }
}