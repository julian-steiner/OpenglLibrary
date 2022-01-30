#pragma once

#include "PCH.h"

namespace programCreator {
GLuint createProgram(const char *vertexShaderSource,
                     const char *fragmentShaderSource);
}