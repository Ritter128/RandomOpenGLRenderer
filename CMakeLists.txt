cmake_minimum_required(VERSION 3.20.3)

project(LEARNCMAKE)

add_executable(${PROJECT_NAME} main.cpp shaders.cpp shaders.h 
vertexbuffer.cpp vertexbuffer.h indexbuffer.cpp indexbuffer.h
vertexarray.cpp vertexarray.h texture.cpp texture.h
renderer.cpp renderer.h
) 

add_subdirectory(dep/glfw)
add_subdirectory(dep/glad)
add_subdirectory(dep/stb)


target_include_directories(${PROJECT_NAME}
    PUBLIC dep/glfw/include
    PUBLIC dep/glad/include
    PUBLIC dep/glm
    PUBLIC dep/stb
)

target_link_directories(${PROJECT_NAME}
    PRIVATE dep/glfw/src
    PRIVATE dep/glad/src
    PRIVATE dep/glm/glm
)

target_link_libraries(${PROJECT_NAME} glfw glad stb)