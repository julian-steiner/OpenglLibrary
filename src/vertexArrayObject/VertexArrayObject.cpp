#include "vertexArrayObject/VertexArrayObject.h"
#include "buffer/BufferHandler.h"

vertexArrayObject::VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1, &this->rendererID);
    this->handlerID = bufferHandler::BufferHandler::getInstance()->registerVertexArrayObject();
    initialize();
}

void vertexArrayObject::VertexArrayObject::addBuffer(buffer::Buffer buffer){
    bind();
    buffer.bind();
}

void vertexArrayObject::VertexArrayObject::bind() {
    glBindVertexArray(this->getRendererID());
    bufferHandler::BufferHandler::getInstance()->setBoundVertexArrayObject(this->handlerID);
}

void vertexArrayObject::VertexArrayObject::unbind() {
    glBindVertexArray(0);
}

void vertexArrayObject::VertexArrayObject::initialize() {
    if (! isInitialized())
    {
        initialized = true;
    }
}