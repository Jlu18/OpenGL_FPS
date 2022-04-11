#Let's test the newest version(3.16) and see how backward it can go)
cmake_minimum_required(VERSION 3.16)
project(OpenGL_FPS  
    VERSION 0.0.0
    DESCRIPTION "First Person Game Made in OpenGL"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

#Dependencies
find_package(SDL2 REQUIRED COMPONENTS main)
find_package(GLEW REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

add_subdirectory(src)