#include "shader/ShaderProgram.h"
#include "shader/Shader.h"
#include "shader/ShaderProgramLinker.h"
#include <string>
#include <utility>
#include <vector>

shader::ShaderProgram::ShaderProgram() {
  this->rendererID = glCreateProgram();
  this->shaders = std::vector<shader::Shader>();
}

void shader::ShaderProgram::bind() {
  initialize();
  glUseProgram(this->rendererID);
}

void shader::ShaderProgram::unbind() { glUseProgram(0); }

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

GLint shader::ShaderProgram::getUniformLocation(const std::string &name) {
  if (this->uniformLocationCache.find(name) !=
      this->uniformLocationCache.end()) {
    return this->uniformLocationCache[name];
  }
  GLint location = glGetUniformLocation(getRendererID(), name.c_str());
  if (location != -1) {
    this->uniformLocationCache.insert(
        std::pair<std::string, GLuint>(name, location));
  }
  return location;
}

void shader::ShaderProgram::setUniform1f(const std::string &name,
                                         const float &value) {
  glUniform1f(getUniformLocation(name), value);
}

void shader::ShaderProgram::setUniform2f(const std::string &name,
                                         const float &value,
                                         const float &value2) {
  glUniform2f(getUniformLocation(name), value, value2);
}

void shader::ShaderProgram::setUniform3f(const std::string &name,
                                         const float &value,
                                         const float &value2,
                                         const float &value3) {
  glUniform3f(getUniformLocation(name), value, value2, value3);
}

void shader::ShaderProgram::setUniform4f(const std::string &name,
                                         const float &value,
                                         const float &value2,
                                         const float &value3,
                                         const float &value4) {
  glUniform4f(getUniformLocation(name), value, value2, value3, value4);
}

void shader::ShaderProgram::setUniform1i(const std::string &name,
                                         const int &value) {
  glUniform1i(getUniformLocation(name), value);
}

void shader::ShaderProgram::setUniform2i(const std::string &name,
                                         const int &value, const int &value2) {
  glUniform2i(getUniformLocation(name), value, value2);
}

void shader::ShaderProgram::setUniform3i(const std::string &name,
                                         const int &value, const int &value2,
                                         const int &value3) {
  glUniform3i(getUniformLocation(name), value, value2, value3);
}

void shader::ShaderProgram::setUniform4i(const std::string &name,
                                         const int &value, const int &value2,
                                         const int &value3, const int &value4) {
  glUniform4i(getUniformLocation(name), value, value2, value3, value4);
}

void shader::ShaderProgram::setUniform1ui(const std::string &name,
                                         const unsigned int &value) {
  glUniform1ui(getUniformLocation(name), value);
}

void shader::ShaderProgram::setUniform2ui(const std::string &name,
                                         const unsigned int &value, const unsigned int &value2) {
  glUniform2ui(getUniformLocation(name), value, value2);
}

void shader::ShaderProgram::setUniform3ui(const std::string &name,
                                         const unsigned int &value, const unsigned int &value2,
                                         const unsigned int &value3) {
  glUniform3ui(getUniformLocation(name), value, value2, value3);
}

void shader::ShaderProgram::setUniform4ui(const std::string &name,
                                         const unsigned int &value, const unsigned int &value2,
                                         const unsigned int &value3, const unsigned int &value4) {
  glUniform4ui(getUniformLocation(name), value, value2, value3, value4);
}