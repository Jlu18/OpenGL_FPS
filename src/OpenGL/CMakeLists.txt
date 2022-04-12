#OpenGL CMake
set(OPENGL_HEADERS
    ${PROJECT_SOURCE_DIR}/include/OpenGL/VertexBufferLayout.h
    ${PROJECT_SOURCE_DIR}/include/OpenGL/VertexArray.h
    ${PROJECT_SOURCE_DIR}/include/OpenGL/Buffer.h
    ${PROJECT_SOURCE_DIR}/include/OpenGL/Mesh.h
)

set(OPENGL_SOURCES
    VertexBufferLayout.cpp
    VertexArray.cpp
    Buffer.cpp
    Mesh.cpp
)

add_library(opengl
    ${OPENGL_HEADERS}
    ${OPENGL_SOURCES}
)

#Add include directories to the target(opengl)
target_include_directories(opengl
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/OpenGL
)