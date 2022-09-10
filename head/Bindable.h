#pragma once

#include "PCH.hpp"

class Bindable {
protected:
  GLuint rendererID;
public:
  virtual void bind() = 0;
  virtual void unbind() = 0;
  GLuint getRendererID() const {return rendererID;}
};