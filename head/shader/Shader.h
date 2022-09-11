#pragma once

#include "Initializable.h"
#include "PCH.hpp"
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
  Shader(GLenum shaderType, const char* filepath) : shaderType(shaderType), sourceCode(loadSourceCode(filepath)) {compile();};
  // Shader(GLenum shaderType, const char* filepath) : shaderType(shaderType), sourceCode(filepath) {compile();};

  /**
   * @brief Get the renderer ID of the shader
   * 
   * @return the Shader id 
   */
  GLuint getShaderID() const;
  
  static const char* loadSourceCode(const char* filepath);

  /**
   * @brief Get the type of the shader
   * 
   * @return the shader type 
   */
  GLenum getShaderType() const;

  /**
   * @brief Get the source code of the shader
   * 
   * @return the source code
   */
  const char* getSourceCode() const;

  /**
   * @brief Delete the shader
   * 
   */
  void deleteShader();
};
} // namespace shader