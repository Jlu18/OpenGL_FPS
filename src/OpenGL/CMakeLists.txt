set(OPENGL_SRCS
    Buffer.cpp
    Mesh.cpp
    VertexArray.cpp
)

add_library(opengl
    ${OPENGL_SRCS}
)

#Add include directories to the target(opengl)
target_include_directories(opengl
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)