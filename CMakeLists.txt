cmake_minimum_required(VERSION 3.20.3)

project(LEARNCMAKE)

add_executable(${PROJECT_NAME} main.c) 

add_subdirectory(XWIN16)
add_subdirectory(SEGGS)
add_subdirectory(dep/glfw)

target_include_directories(${PROJECT_NAME}
    PRIVATE XWIN16 SEGGS
)

target_link_libraries(${PROJECT_NAME} xwin16 seggs)