#pragma once

#include "PCH.h"

namespace shader {
class ShaderSource {
protected:
  const char *sourceCode;
  const GLenum type;

public:
  ShaderSource(const char *sourceCode, GLenum type) : sourceCode(sourceCode), type(type){};
  const GLenum getShaderType() const { return this->type; } 
  const char *getSourceCode() const {return this->sourceCode;}
};
} // namespace shader