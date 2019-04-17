cmake_minimum_required(VERSION 2.8)

project(MiniWorld)

file(GLOB miniWorld_SRC
    "src/*.h"
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} "main.cpp" ${miniWorld_SRC})
