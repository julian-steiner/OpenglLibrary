#include "ProgramCreator.h"

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

  const char *vertexShaderSource =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";

  const char *fragmentShaderSource =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()\n"
      "{\n"
      " FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\0";

  GLuint shaderProgram =
      programCreator::createProgram(vertexShaderSource, fragmentShaderSource);

  // VERTEX ARRAY
  GLuint vertexArrayObject;
  glGenVertexArrays(1, &vertexArrayObject);
  glBindVertexArray(vertexArrayObject);

  // VERTEX BUFFER
  GLfloat verteces[] = {0.5f,  0.5f,  0.0f, 0.5f,  -0.5f, 0.0f,
                        -0.5f, -0.5f, 0.0f, -0.5f, 0.5f,  0.0f};
  GLuint vertexBufferObject;
  glGenBuffers(1, &vertexBufferObject);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verteces), verteces, GL_STATIC_DRAW);

  // ELEMENT BUFFER
  GLuint indeces[] = {0, 1, 3, 1, 2, 3};

  unsigned int elementBufferObject;
  glGenBuffers(1, &elementBufferObject);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces,
               GL_STATIC_DRAW);

  // VERTEX ATTRIBUTES
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                        (const void *)0);
  glEnableVertexAttribArray(0);

  do {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shaderProgram);

    glBindVertexArray(vertexArrayObject);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  } while (glfwWindowShouldClose(window) == 0);

  glfwTerminate();
  return 0;
}