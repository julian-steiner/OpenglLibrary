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

            /**
             * @brief Adds a buffer to the vao
             * 
             * @param buffer 
             */
            void addBuffer(buffer::Buffer buffer);

            /**
             * @brief Binds the vao
             * 
             */
            void bind() override;

            /**
             * @brief Unbinds the vao
             * 
             */
            void unbind() override;

            /**
             * @brief Initializes the vao
             * 
             */
            void initialize() override;
    };
}