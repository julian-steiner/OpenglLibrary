#include "ShaderProgramLinker.h"
#include "Shader.h"
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

// GLuint shaderProgramLinker::ShaderProgramLinker::linkProgram(shader::Shader vertexShader, shader::Shader fragmentShader) {
//   GLuint shaderProgram = glCreateProgram();
//   glAttachShader(shaderProgram, vertexShader.getShaderID());
//   glAttachShader(shaderProgram, fragmentShader.getShaderID());
//   glLinkProgram(shaderProgram);

//   glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//   if (!success) {
//     glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//     std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n"
//               << infoLog << "\n";
//   }

//   return shaderProgram;
// }

GLuint shaderProgramLinker::ShaderProgramLinker::linkProgram(std::vector<shader::Shader>& shaders) {
  GLuint shaderProgram = glCreateProgram();
  for (shader::Shader& cShader : shaders)
  {
      glAttachShader(shaderProgram, cShader.getShaderID());
  }
//   glAttachShader(shaderProgram, vertexShader.getShaderID());
//   glAttachShader(shaderProgram, fragmentShader.getShaderID());
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n"
              << infoLog << "\n";
  }

  return shaderProgram;
}