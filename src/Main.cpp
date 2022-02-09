#include "buffer/BufferAttribute.h"
#include "buffer/IndexBuffer.h"
#include "buffer/VertexBuffer.h"
#include "glm/detail/qualifier.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/ext/vector_float4.hpp"
#include "shader/FragmentShader.h"
#include "shader/Shader.h"
#include "shader/ShaderProgram.h"
#include "shader/VertexShader.h"
#include "vertexArrayObject/VertexArrayObject.h"
#include <array>
#include <vector>
#include "texture/Texture2D.h"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

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

  GLFWwindow *window = glfwCreateWindow(720, 720, "Test", NULL, NULL);
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

  glViewport(0, 0, 720, 720);

  glfwSetWindowSizeCallback(window, framebuffer_size_callback);

  const char *vertexShaderSourceCode =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "layout (location = 1) in vec2 texCoord;\n"
      "out vec2 textureCoord;\n"
      "void main()\n"
      "{\n"
      " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      " textureCoord = texCoord;\n"
      "}\0";

  const char *fragmentShaderSourceCode =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "in vec2 textureCoord;\n"
      "uniform sampler2D texture_s;"
      "void main()\n"
      "{\n"
      " FragColor = texture(texture_s, textureCoord);\n"
      "}\0";

  shader::VertexShader vertexShader =
      shader::VertexShader(vertexShaderSourceCode);
  shader::FragmentShader fragmentShader =
      shader::FragmentShader(fragmentShaderSourceCode);

  shader::ShaderProgram shaderProgram;
  shaderProgram.addShader(vertexShader);
  shaderProgram.addShader(fragmentShader);

  struct Vertex{
    glm::vec3 position;
    glm::vec2 texCoord;
  };

  Vertex upRight;
  upRight.position = glm::vec3(0.5, 0.5, 0.0);
  upRight.texCoord = glm::vec2(1, 1);

  Vertex downRight;
  downRight.position = glm::vec3(0.5, -0.5, 0.0);
  downRight.texCoord = glm::vec2(1, 0);

  Vertex upLeft;
  upLeft.position = glm::vec3(-0.5, 0.5, 0.0);
  upLeft.texCoord = glm::vec2(0, 1);

  Vertex downLeft;
  downLeft.position = glm::vec3(-0.5, -0.5, 0.0);
  downLeft.texCoord = glm::vec2(0, 0);

  std::array<Vertex, 4> verteces = {upRight, downRight, upLeft, downLeft};

  buffer::VertexBuffer vertexBuffer = buffer::VertexBuffer();
  vertexBuffer.loadData(verteces, GL_STATIC_DRAW);
  vertexBuffer.addAttribute(buffer::BufferAttribute(GL_FLOAT, 3));
  vertexBuffer.addAttribute(buffer::BufferAttribute(GL_FLOAT, 2));

  std::array<unsigned int, 6> elements = {0, 1, 2, 2, 3, 1};
  buffer::IndexBuffer indexBuffer = buffer::IndexBuffer();
  indexBuffer.loadData(elements, GL_STATIC_DRAW);

  // Vertex Array Object
  vertexArrayObject::VertexArrayObject vao = vertexArrayObject::VertexArrayObject();
  vao.addBuffer(vertexBuffer);
  vao.addBuffer(indexBuffer);

  texture::Texture tex = texture::Texture2D("texture2.jpg");

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram.bind();

    tex.bind();
  
    vao.bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  } while (glfwWindowShouldClose(window) == 0);

  glfwTerminate();
  return 0;
}