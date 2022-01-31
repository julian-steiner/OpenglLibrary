cmake_minimum_required(VERSION 3.22)

project("OpenGL-Library")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(lib/glew/include ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} head)

set(Source 
    src/Main.cpp
    src/Shader.cpp
    src/FragmentShader.cpp
    src/VertexShader.cpp
    src/ShaderCompiler.cpp
    src/ShaderProgram.cpp
    src/ShaderProgramLinker.cpp)

add_executable(${PROJECT_NAME} ${Source})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)
target_precompile_headers(${PROJECT_NAME} PUBLIC head/PCH.h)