set(RESOURCE_SRCS
    ResourceManager.cpp
    Setting.cpp
    Shader.cpp
    Texture2D.cpp
)

add_library(resource
    ${RESOURCE_SRCS}
)

target_link_libraries(resource
    PUBLIC
    opengl_fps
)

target_include_directories(resource
    PUBLIC
    "${PROJECT_SOURCE_DIR}/include/"
)