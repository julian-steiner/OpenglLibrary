#include "buffer/IndexBuffer.h"
#include "buffer/VertexBuffer.h"
#include "shader/FragmentShader.h"
#include "shader/Shader.h"
#include "shader/ShaderProgram.h"
#include "shader/VertexShader.h"
#include "vertexArrayObject/VertexArrayObject.h"
#include <array>
#include <vector>
#include "texture/Texture2D.h"

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
      "layout (location = 1) in vec3 color;\n"
      "layout (location = 2) in vec2 texCoord;\n"
      "out vec4 vertexColor;\n"
      "out vec2 textureCoord;\n"
      "void main()\n"
      "{\n"
      " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      " textureCoord = texCoord;\n"
      " vertexColor = vec4(color, 1.0f);\n"
      "}\0";

  const char *fragmentShaderSourceCode =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "in vec4 vertexColor;\n"
      "in vec2 textureCoord;\n"
      "uniform sampler2D texture1;\n"
      "uniform sampler2D texture2;\n"
      "void main()\n"
      "{\n"
      " FragColor = mix(texture(texture1, textureCoord), texture(texture2, textureCoord), 0.4);\n"
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
  std::array<float, 32> verteces = {0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,
                                    0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
                                   -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
                                   -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f};

  std::array<float, 8> texCoords = {1.0f, 1.0f,
                                    1.0f, 0.0f,
                                    0.0f, 0.0f,
                                    0.0f, 1.0f};

  buffer::VertexBuffer vertexBuffer = buffer::VertexBuffer();
  vertexBuffer.loadData(verteces, GL_STATIC_DRAW);
  vertexBuffer.addAttribute(buffer::BufferAttribute(GL_FLOAT, 3));
  vertexBuffer.addAttribute(buffer::BufferAttribute(GL_FLOAT, 3));

  buffer::VertexBuffer textureCoords = buffer::VertexBuffer();
  textureCoords.loadData(texCoords, GL_STATIC_DRAW);
  textureCoords.addAttribute(buffer::BufferAttribute(GL_FLOAT, 2));

  std::array<unsigned int, 6> elements = {0, 1, 2, 0, 3, 2};
  buffer::IndexBuffer indexBuffer = buffer::IndexBuffer();
  indexBuffer.loadData(elements, GL_STATIC_DRAW);

  // Vertex Array Object
  vertexArrayObject::VertexArrayObject vao = vertexArrayObject::VertexArrayObject();
  vao.addBuffer(vertexBuffer);
  vao.addBuffer(textureCoords);
  vao.addBuffer(indexBuffer);

  texture::Texture tex = texture::Texture2D("texture.jpg");
  texture::Texture tex2 = texture::Texture2D("texture2.jpg");
  tex2.setSlot(1);

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram.bind();
    shaderProgram.setUniform1i("texture1", 0);
    shaderProgram.setUniform1i("texture2", 1);

    tex.bind();
    tex2.bind();
  
    vao.bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  } while (glfwWindowShouldClose(window) == 0);

  glfwTerminate();
  return 0;
}