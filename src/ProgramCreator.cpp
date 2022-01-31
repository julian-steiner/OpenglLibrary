#include "ProgramCreator.h"
#include "FragmentShader.h"
#include "Shader.h"
#include "ShaderProgramLinker.h"
#include "VertexShader.h"
#include <exception>
#include <vector>

GLuint programCreator::createProgram(const char *vertexShaderSource,
                                     const char *fragmentShaderSource) {

  shader::Shader vertexShader = shader::VertexShader(vertexShaderSource);
  shader::Shader fragmentShader = shader::FragmentShader(fragmentShaderSource);

  std::vector<shader::Shader> shaders = std::vector<shader::Shader>({vertexShader, fragmentShader});
  GLuint shaderProgram = shaderProgramLinker::ShaderProgramLinker::getInstance()->linkProgram(shaders);

  vertexShader.deleteShader();
  fragmentShader.deleteShader();

  return shaderProgram;
}