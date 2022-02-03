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

void bufferHandler::BufferHandler::setBoundVertexArrayObject(int id) {
  if (this->vertexArrayObjectList.size() < id) {
    for (int i = 0; i < id - this->vertexArrayObjectList.size() + 2; i++) {
      this->vertexArrayObjectList.push_back(0);
      std::cout << "ADDED TO THE ARRAY" << std::endl;
    }
  }

  this->boundVertexArrayObject = id;
}
