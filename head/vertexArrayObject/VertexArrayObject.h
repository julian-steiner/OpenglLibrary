#pragma once

#include "Bindable.h"
#include "Initializable.h"
#include "buffer/Buffer.h"
namespace vertexArrayObject
{
    class VertexArrayObject : public Bindable, Initializable
    {
        private:
            GLuint handlerID;
        public:
            VertexArrayObject();
            void addBuffer(buffer::Buffer buffer);
            void bind() override;
            void unbind() override;
            void initialize() override;
    };
}