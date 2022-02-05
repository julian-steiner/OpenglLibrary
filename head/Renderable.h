#pragma once

#include "PCH.h"

class Renderable {
protected:
  GLuint rendererID;
public:
  virtual void bind() = 0;
  virtual void unbind() = 0;
  GLuint getRendererID() const {return rendererID;}
};