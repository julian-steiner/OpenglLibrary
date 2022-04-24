#include "buffer/BufferAttribute.h"
#include "buffer/IndexBuffer.h"
#include "buffer/VertexBuffer.h"
#include "glm/detail/qualifier.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/quaternion_transform.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/ext/vector_float4.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/string_cast.hpp"
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
#include "glm/matrix.hpp"
#include "glm/gtc/matrix_transform.hpp"

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

  glEnable(GL_DEPTH_TEST);

  const char *vertexShaderSourceCode =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "layout (location = 1) in vec2 texCoord;\n"
      "out vec2 textureCoord;\n"
      "uniform mat4 model;\n"
      "uniform mat4 view;\n"
      "uniform mat4 projection;\n"
      "void main()\n"
      "{\n"
      " gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
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

  std::array<float, 5 * 36> verteces = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f};

  buffer::VertexBuffer vertexBuffer = buffer::VertexBuffer();
  vertexBuffer.loadData(verteces, GL_STATIC_DRAW);
  vertexBuffer.addAttribute(buffer::BufferAttribute(GL_FLOAT, 3));
  vertexBuffer.addAttribute(buffer::BufferAttribute(GL_FLOAT, 2));

  // Vertex Array Object
  vertexArrayObject::VertexArrayObject vao = vertexArrayObject::VertexArrayObject();
  vao.addBuffer(vertexBuffer);

  texture::Texture tex = texture::Texture2D("texture.jpg");

  glm::mat4 model = glm::mat4(1.0f);
  model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

  glm::mat4 viewMatrix = glm::mat4(1.0f);
  viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));

  glm::mat4 projection = glm::perspective(glm::radians(60.0f), 1000.0f / 1000.0f, 0.1f, 100.0f);

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    model = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));  

    shaderProgram.bind();
    shaderProgram.setUniformMatrix4x4("model", model);
    shaderProgram.setUniformMatrix4x4("view", viewMatrix);
    shaderProgram.setUniformMatrix4x4("projection", projection);

    tex.bind();
    vao.bind();

    glDrawArrays(GL_TRIANGLES, 0, 36);

    glfwSwapBuffers(window);
    glfwPollEvents();
  } while (glfwWindowShouldClose(window) == 0);

  glfwTerminate();
  return 0;
}