#ECS CMake

set(ECS_HEADERS
    ${PROJECT_SOURCE_DIR}/include/ECS/Entity.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Camera.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Components.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Player.h
    #${PROJECT_SOURCE_DIR}/include/ECS/Component/Raycast.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Renderable.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Transform.h
)

set(ECS_SOURCES
    Entity.cpp
    Component/Player.cpp
    #Component/Raycast.cpp
)

add_library(ecs
    ${ECS_HEADERS}
    ${ECS_SOURCES}
)

target_link_libraries(ecs
    PRIVATE
    state
)

target_include_directories(ecs
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/ECS
)