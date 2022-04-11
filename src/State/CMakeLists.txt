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

target_include_directories(state
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include/
    ${PROJECT_SOURCE_DIR}/include/State
)