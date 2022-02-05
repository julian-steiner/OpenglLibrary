#include "shader/ShaderProgramLinker.h"
#include "shader/Shader.h"
#include <memory>

std::shared_ptr<shaderProgramLinker::ShaderProgramLinker>
    shaderProgramLinker::ShaderProgramLinker::instance = 0;

std::shared_ptr<shaderProgramLinker::ShaderProgramLinker>
shaderProgramLinker::ShaderProgramLinker::getInstance() {
  if (shaderProgramLinker::ShaderProgramLinker::instance == nullptr) {
    shaderProgramLinker::ShaderProgramLinker::instance = std::make_shared<ShaderProgramLinker>(ShaderProgramLinker());
  }
  return shaderProgramLinker::ShaderProgramLinker::instance;
}

void shaderProgramLinker::ShaderProgramLinker::linkProgram(shader::ShaderProgram* program) {
  for (shader::Shader& cShader : program->shaders)
  {
      glAttachShader(program->getRendererID(), cShader.getShaderID());
  }
  glLinkProgram(program->getRendererID());

  glGetProgramiv(program->getRendererID(), GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(program->getRendererID(), 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n"
              << infoLog << "\n";
  }
}