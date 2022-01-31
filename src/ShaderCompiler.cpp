#include "ShaderCompiler.h"
#include <memory>

std::shared_ptr<shaderCompiler::ShaderCompiler>
    shaderCompiler::ShaderCompiler::instance = 0;

std::shared_ptr<shaderCompiler::ShaderCompiler>
shaderCompiler::ShaderCompiler::getInstance() {
  if (ShaderCompiler::instance == nullptr) {
    ShaderCompiler::instance =
        std::make_shared<shaderCompiler::ShaderCompiler>(shaderCompiler::ShaderCompiler());
  }
  return ShaderCompiler::instance;
}