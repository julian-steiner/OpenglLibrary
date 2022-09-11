#include "shader/Shader.h"
#include "shader/ShaderCompiler.h"

GLuint shader::Shader::getShaderID() const { return this->id; }

GLenum shader::Shader::getShaderType() const { return this->shaderType; }

const char *shader::Shader::getSourceCode() const { return this->sourceCode; }

const char* shader::Shader::loadSourceCode(const char* filepath) 
{
  std::ifstream sourceFile;
  sourceFile.open(filepath);
  std::string sourceCode;
  char* buffer;

  if (sourceFile.is_open())
  {
    sourceFile.seekg(0,std::ios::end);
    std::streampos length = sourceFile.tellg();
    sourceFile.seekg(0,std::ios::beg);

    buffer = (char*) malloc(length);
    sourceFile.read(buffer, length);
  }
  sourceFile.close();

  return buffer;
}

void shader::Shader::deleteShader() { glDeleteShader(this->getShaderID()); }

void shader::Shader::compile() {
  shaderCompiler::ShaderCompiler::getInstance()->compileShader(this);
}

void shader::Shader::initialize() {
  if (isInitialized()) {
    return;
  } else {
    compile();
    initialized = true;
  }
}