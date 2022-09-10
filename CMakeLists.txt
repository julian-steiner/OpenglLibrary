cmake_minimum_required(VERSION 3.22)

project("OpenGL-Library")

find_package(OpenGL REQUIRED)
# find_package(GLEW REQUIRED)
# find_package(glfw3 REQUIRED)

set(GLEW_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/lib/glew/include)
set(GLFW_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/lib/glfw-3.3.8/include)
set(GLFW_LIBRARIES libglfw3.a)

#################################
# Generate Docs
#################################
OPTION(BUILD_WITH_DOCS "Generate Docs" ON)
IF(TASKSCH_BUILD_WITH_DOCS)
	ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/docs)
ENDIF()

include_directories(${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} head lib/stb_image lib)

set(Source 
    lib/stb_image/stb_image.cpp
    src/Main.cpp
    src/shader/Shader.cpp
    src/shader/ShaderCompiler.cpp
    src/shader/ShaderProgram.cpp
    src/shader/ShaderProgramLinker.cpp
    src/buffer/Buffer.cpp
    src/vertexArrayObject/VertexArrayObject.cpp
    src/buffer/BufferHandler.cpp
    src/texture/Texture.cpp
    lib/glew/glew.c)

add_subdirectory(lib/glfw-3.3.8)

add_executable(${PROJECT_NAME} ${Source})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)
# target_precompile_headers(${PROJECT_NAME} PUBLIC head/PCH.hpp)