#Resource CMake

set(RESOURCE_HEADERS
    ${PROJECT_SOURCE_DIR}/include/Resource/Shader.h
    ${PROJECT_SOURCE_DIR}/include/Resource/Texture2D.h
    ${PROJECT_SOURCE_DIR}/include/Resource/Model.h
    ${PROJECT_SOURCE_DIR}/include/Resource/Setting.h
    ${PROJECT_SOURCE_DIR}/include/Resource/ResourceManager.h
)

set(RESOURCE_SOURCES
    Shader.cpp
    Texture2D.cpp
    Model.cpp
    Setting.cpp
    ResourceManager.cpp
)

add_library(resource
    ${RESOURCE_HEADERS}
    ${RESOURCE_SOURCES}
)

target_link_libraries(resource
    PUBLIC
    opengl
    STB_IMAGE
    ${ASSIMP_LIBRARIES}
)

target_include_directories(resource
    PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include/
    ${PROJECT_SOURCE_DIR}/include/Resource
)