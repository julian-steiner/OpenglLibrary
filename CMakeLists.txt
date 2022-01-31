cmake_minimum_required(VERSION 3.22)

project("OpenGL-Library")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(lib/glew/include ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} head)

set(Source 
    src/Main.cpp
    src/shader/Shader.cpp
    src/shader/FragmentShader.cpp
    src/shader/VertexShader.cpp
    src/shader/ShaderCompiler.cpp
    src/shader/ShaderProgram.cpp
    src/shader/ShaderProgramLinker.cpp)

add_executable(${PROJECT_NAME} ${Source})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)
target_precompile_headers(${PROJECT_NAME} PUBLIC head/PCH.h)