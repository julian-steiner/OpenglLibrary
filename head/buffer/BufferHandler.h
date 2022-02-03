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
  GLuint generateVertexAttribPointerID();
  void setBoundVertexArrayObject(int id);
};
} // namespace bufferHandler