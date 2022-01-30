cmake_minimum_required(VERSION 3.22)

project("OpenGL-Library")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(lib/glew/include ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} head)

add_executable(${PROJECT_NAME} src/Main.cpp src/ProgramCreator.cpp src/Shader.cpp src/VertexShader.cpp src/FragmentShader.cpp)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)
target_precompile_headers(${PROJECT_NAME} PUBLIC head/PCH.h)