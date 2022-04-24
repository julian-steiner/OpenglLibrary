#pragma once

#include <memory>
#include <vector>
#include "PCH.h"

namespace bufferHandler {
class BufferHandler {
private:
  int boundVertexArrayObject;
  std::vector<GLuint> vertexArrayObjectList;
  BufferHandler() : vertexArrayObjectList(std::vector<GLuint>()), boundVertexArrayObject(0) {vertexArrayObjectList.push_back(0);}

public:
  static std::shared_ptr<BufferHandler> getInstance();
  int getBoundVertexArrayObject();

  /**
   * @brief Generates a valid vertexAttribPointerID
   * 
   * @return GLuint The vertexAttribPointerID
   */
  GLuint generateVertexAttribPointerID();

  /**
   * @brief Registers a vao to the handler
   * 
   * @return GLuint The handler id of the vao
   */
  GLuint registerVertexArrayObject();

  /**
   * @brief Set the bound vertexArrayObject 
   * 
   * @param id Id to set the bound vao to
   */
  void setBoundVertexArrayObject(int id);
};
} // namespace bufferHandler