#Renderer CMake

set(PRIMITIVE_HEADERS
    ${PROJECT_SOURCE_DIR}/include/Renderer/Primitive/Box.h
    ${PROJECT_SOURCE_DIR}/include/Renderer/Primitive/Plane.h
    ${PROJECT_SOURCE_DIR}/include/Renderer/Primitive/Square.h
)

set(RENDERER_HEADERS
    ${PROJECT_SOURCE_DIR}/include/Renderer/Renderer.h
    ${PROJECT_SOURCE_DIR}/include/Renderer/Renderer2D.h
)

set(PRIMITIVE_SOURCES
    Primitive/Plane.cpp
)

set(RENDERER_SOURCES
    Renderer.cpp
    Renderer2D.cpp
)

add_library(renderer
    ${RENDERER_HEADERS}
    ${RENDERER_SOURCES}
    ${PRIMITIVE_HEADERS}
    ${PRIMITIVE_SOURCES}
)


#Add include directories to the target(opengl)
target_include_directories(renderer
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/Renderer
)