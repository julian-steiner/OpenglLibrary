#include "buffer/BufferAttribute.h"
#include "buffer/IndexBuffer.h"
#include "buffer/VertexBuffer.h"
#include "shader/FragmentShader.h"
#include "shader/Shader.h"
#include "shader/ShaderProgram.h"
#include "shader/VertexShader.h"
#include "vertexArrayObject/VertexArrayObject.h"
#include <array>
#include <vector>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

int main() {
  if (!glfwInit()) {
    std::fprintf(stderr, "Failed to initialize GLFW\n");
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(720, 480, "Test", NULL, NULL);
  if (window == NULL) {
    std::fprintf(stderr, "Failed to create window\n");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glewExperimental = true;
  if (glewInit() != GLEW_OK) {
    std::fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }

  glViewport(0, 0, 720, 480);

  glfwSetWindowSizeCallback(window, framebuffer_size_callback);

  const char *vertexShaderSourceCode =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "layout (location = 1) in vec3 color;"
      "out vec4 vertexColor;"
      "void main()\n"
      "{\n"
      " vertexColor = vec4(color, 1.0);"
      " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";

  const char *fragmentShaderSourceCode =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "in vec4 vertexColor;"
      "void main()\n"
      "{\n"
      " FragColor = vertexColor;\n"
      "}\0";

  shader::VertexShader vertexShader =
      shader::VertexShader(vertexShaderSourceCode);
  shader::FragmentShader fragmentShader =
      shader::FragmentShader(fragmentShaderSourceCode);

  shader::ShaderProgram shaderProgram;
  shaderProgram.addShader(vertexShader);
  shaderProgram.addShader(fragmentShader);

  // VERTEX ARRAY
  GLuint vertexArrayObject;
  glGenVertexArrays(1, &vertexArrayObject);
  glBindVertexArray(vertexArrayObject);

  // VERTEX BUFFER
  std::array<float, 12> verteces = {0.5f,  0.5f,  0.0f,
                                    0.5f,  -0.5f, 0.0f,
                                    -0.5f, -0.5f, 0.0f,
                                    -0.5f, 0.5f,  0.0f};

  std::array<float, 12> colors = {0.0f,  1.0f,  0.0f,
                                    0.0f,  0.0f, 0.0f,
                                    0.0f, 0.0f, 1.0f,
                                    0.0f, 0.0f,  0.0f};

  buffer::VertexBuffer vertexBuffer = buffer::VertexBuffer();
  vertexBuffer.loadData(verteces, GL_STATIC_DRAW);

  buffer::VertexBuffer colorBuffer = buffer::VertexBuffer();
  colorBuffer.loadData(colors, GL_STATIC_DRAW);

  vertexBuffer.addAttribute(buffer::BufferAttribute(GL_FLOAT, 3));
  colorBuffer.addAttribute(buffer::BufferAttribute(GL_FLOAT, 3));

  // ELEMENT BUFFER
  std::array<unsigned int, 6> indeces = {0, 1, 3, 1, 2, 3};

  buffer::IndexBuffer indexBuffer = buffer::IndexBuffer();
  indexBuffer.loadData(indeces, GL_STATIC_DRAW);

  vertexArrayObject::VertexArrayObject vao = vertexArrayObject::VertexArrayObject();
  vao.addBuffer(vertexBuffer);
  vao.addBuffer(colorBuffer);
  // vao.addBuffer(indexBuffer);

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram.bind();

    vao.bind();

    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  } while (glfwWindowShouldClose(window) == 0);

  glfwTerminate();
  return 0;
}