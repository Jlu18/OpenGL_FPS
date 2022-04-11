set(PRIMITIVE_SRCS
    Primitive/Plane.cpp
)

set(RENDERER_SRCS
    Renderer.cpp
    Renderer2D.cpp
)

add_library(renderer
    ${PRIMITIVE_SRCS}
    ${RENDERER_SRCS}
)
