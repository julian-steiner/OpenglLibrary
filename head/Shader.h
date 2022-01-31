#pragma once

#include "Initializable.h"
#include "PCH.h"
#include <memory>

namespace shaderCompiler {
  class ShaderCompiler;
}

namespace shader {
class Shader : Initializable{
friend shaderCompiler::ShaderCompiler;

protected:
  const char *sourceCode;
  GLuint id;
  const GLenum shaderType;

protected:
  void compile();
  void initialize() override;

public:
  Shader(GLenum shaderType, const char* sourceCode) : shaderType(shaderType), sourceCode(sourceCode){};
  GLuint getShaderID();
  GLenum getShaderType() const;
  const char* getSourceCode() const;
  void deleteShader();
};
} // namespace shader