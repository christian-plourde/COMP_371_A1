#When using this template, all you need to do is change the name of the project (the second line)

cmake_minimum_required(VERSION 3.3)
project(COMP_371_A1)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Loaders/ShaderLoader.cpp Loaders/ObjectLoader.cpp Controls/KeyboardControls.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/GLM/glm)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/GLFW/include)
find_library(GLFW_LIBRARIES NAMES glfw3 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/GLFW/lib-mingw-w64")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/GLEW/include/GL)
find_library(GLEW_LIBRARIES NAMES glew32 PATHS "${CMAKE_CURRENT_SOURCE_DIR}/GLEW/lib")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

# Linking GLFW and OGL
target_link_libraries(${CMAKE_PROJECT_NAME} ${OPENGL_LIBRARY} ${GLEW_LIBRARIES} ${GLFW_LIBRARIES})