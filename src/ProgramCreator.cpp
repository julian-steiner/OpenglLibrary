#include "ProgramCreator.h"
#include "FragmentShader.h"
#include "Shader.h"
#include "VertexShader.h"

GLuint programCreator::createProgram(const char *vertexShaderSource,
                                     const char *fragmentShaderSource) {
  int success;
  char infoLog[512];

  // Create the 2 shaders
  shader::Shader vertexShader = shader::VertexShader(vertexShaderSource);
  shader::Shader fragmentShader = shader::FragmentShader(fragmentShaderSource);

  GLuint shaderProgram;

  // Create the shader program
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader.getShaderID());
  glAttachShader(shaderProgram, fragmentShader.getShaderID());
  glLinkProgram(shaderProgram);

  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n"
              << infoLog << "\n";
  }

  vertexShader.deleteShader();
  fragmentShader.deleteShader();

  return shaderProgram;
}