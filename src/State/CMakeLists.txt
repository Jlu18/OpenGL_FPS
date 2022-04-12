set(STATE_HEADERS
    ${PROJECT_SOURCE_DIR}/include/State/BaseState.h
    ${PROJECT_SOURCE_DIR}/include/State/GameState.h
    ${PROJECT_SOURCE_DIR}/include/State/StateManager.h
)

set(STATE_SOURCES
    BaseState.cpp
    GameState.cpp
    StateManager.cpp
)

add_library(state
    ${STATE_HEADERS}
    ${STATE_SOURCES}
)

target_link_libraries(state
    PUBLIC
    resource
    renderer
    ${SDL2_LIBRARIES}
)

target_include_directories(state
    PUBLIC
    ${SDL2_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include/
    ${PROJECT_SOURCE_DIR}/include/State
)
