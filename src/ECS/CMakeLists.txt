set(ECS_HEADERS
    ${PROJECT_SOURCE_DIR}/include/ECS/Entity.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Camera.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Components.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Player.h
    #${PROJECT_SOURCE_DIR}/include/ECS/Component/Raycast.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Renderable.h
    ${PROJECT_SOURCE_DIR}/include/ECS/Component/Transform.h
)

#Create "ecs" library/target based on cpp files
set(ECS_SOURCES
    Entity.cpp
    Component/Player.cpp
    #Component/Raycast.cpp
)

add_library(ecs
    ${ECS_HEADERS}
    ${ECS_SOURCES}
)

#Add include directories to the target(opengl)
target_include_directories(ecs
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/ECS
)