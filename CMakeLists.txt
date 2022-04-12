#Main CMake

#Let's test the newest version(3.16) and see how backward it can go)
cmake_minimum_required(VERSION 3.16)
project(OpenGL_FPS  
    VERSION 0.0.0
    DESCRIPTION "First Person Game Made in OpenGL"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)


#Dependencies
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL2 REQUIRED COMPONENTS main)
find_package(ASSIMP REQUIRED)

add_library(STB_IMAGE ${PROJECT_SOURCE_DIR}/src/_stb/stb.cpp)
target_include_directories(STB_IMAGE PRIVATE ${PROJECT_SOURCE_DIR}/include/stb)

#Add all of the CMake files in src directory
add_subdirectory(src)

#Create executable from the Application
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/Application.cpp)

#Linking all the necessary libraries to App executable
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${GLEW_LIBRARIES}
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARY} 
    opengl
    ecs
    renderer
    resource
    state
)
message(STATUS "${SDL2_INCLUDE_DIRS}")

#Add in Include so it will be detected in IDE
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include/
)