cmake_minimum_required(VERSION 3.10)
project(MyGameEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

link_directories(lib)

set(SOURCES 
    src/main.cpp 
    src/glad.c
    src/stb.cpp
)

add_executable(myWindow ${SOURCES})

target_link_libraries(myWindow glfw GL dl)