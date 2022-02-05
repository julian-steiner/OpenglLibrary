#pragma once

#include "Bindable.h"
#include "Initializable.h"
#include "PCH.h"
#include "shader/Shader.h"
#include <string>
#include <unordered_map>

namespace shaderProgramLinker {
class ShaderProgramLinker;
}

namespace shader {
class ShaderProgram : Initializable, Bindable {
  friend class shaderProgramLinker::ShaderProgramLinker;

private:
  int id = 0;
  std::vector<shader::Shader> shaders;
  std::unordered_map<std::string, GLuint> uniformLocationCache;

  void initialize() override;
  void linkProgram();
  GLint getUniformLocation(const std::string &name);

public:
  ShaderProgram();
  void addShader(const shader::Shader &shader);
  GLuint getProgramID();
  void bind() override;
  void unbind() override;

  // Uniform setters
  void setUniform1f(const std::string &name, const float &value);
  void setUniform2f(const std::string &name, const float &value,
                    const float &value2);
  void setUniform3f(const std::string &name, const float &value,
                    const float &value2, const float &value3);
  void setUniform4f(const std::string &name, const float &value,
                    const float &value2, const float &value3,
                    const float &value4);

  void setUniform1i(const std::string &name, const int &value);
  void setUniform2i(const std::string &name, const int &value,
                    const int &value2);
  void setUniform3i(const std::string &name, const int &value,
                    const int &value2, const int &value3);
  void setUniform4i(const std::string &name, const int &value,
                    const int &value2, const int &value3, const int &value4);

  void setUniform1ui(const std::string &name, const unsigned int &value);
  void setUniform2ui(const std::string &name, const unsigned int &value,
                     const unsigned int &value2);
  void setUniform3ui(const std::string &name, const unsigned int &value,
                     const unsigned int &value2, const unsigned int &value3);
  void setUniform4ui(const std::string &name, const unsigned int &value,
                     const unsigned int &value2, const unsigned int &value3,
                     const unsigned int &value4);
};
} // namespace shader