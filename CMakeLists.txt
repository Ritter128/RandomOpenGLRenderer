cmake_minimum_required(VERSION 3.20.3)

project(LEARNCMAKE)

add_executable(${PROJECT_NAME} main.c) 

add_subdirectory(dep/glfw)
add_subdirectory(dep/glew)

target_include_directories(${PROJECT_NAME}
    PUBLIC dep/glfw/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE dep/glfw/src
)

target_link_libraries(${PROJECT_NAME} glfw)