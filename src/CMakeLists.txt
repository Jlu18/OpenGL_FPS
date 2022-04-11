#Add cmake from subdirectories
add_subdirectory(ECS)
add_subdirectory(OpenGL)
add_subdirectory(Renderer)
add_subdirectory(Resource)
add_subdirectory(State)

#Create executable
add_executable(app Application.cpp)

#Linking libraries to app
target_link_libraries(app
    PRIVATE
    ecs
    opengl
    renderer
    resource
    state
    ${SDL2_LIBRARIES}
    ${GLEW_LIBRARIES}
)

target_include_directories(app
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include/
)

