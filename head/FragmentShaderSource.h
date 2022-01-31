#pragma once

#include "ShaderSource.h"

namespace shader {
class FragmentShaderSource : public ShaderSource {
public:
  FragmentShaderSource(const char* sourceCode): shader::ShaderSource(sourceCode, GL_FRAGMENT_SHADER) {};
};
} // namespace shader