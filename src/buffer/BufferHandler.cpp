#include "buffer/BufferHandler.h"
#include <cstddef>
#include <iostream>
#include <memory>

std::shared_ptr<bufferHandler::BufferHandler>
bufferHandler::BufferHandler::getInstance() {
  static std::shared_ptr<bufferHandler::BufferHandler> instance =
      std::make_shared<bufferHandler::BufferHandler>(
          bufferHandler::BufferHandler());
  return instance;
}

int bufferHandler::BufferHandler::getBoundVertexArrayObject() {
  return this->boundVertexArrayObject;
}

GLuint bufferHandler::BufferHandler::generateVertexAttribPointerID() {
  int id = this->vertexArrayObjectList.at(getBoundVertexArrayObject());
  this->vertexArrayObjectList.at(getBoundVertexArrayObject()) += 1;
  return id;
}

GLuint bufferHandler::BufferHandler::registerVertexArrayObject()
{
  this->vertexArrayObjectList.push_back(0);
  return this->vertexArrayObjectList.size() - 1;
}

void bufferHandler::BufferHandler::setBoundVertexArrayObject(int id) {
  this->boundVertexArrayObject = id;
}
