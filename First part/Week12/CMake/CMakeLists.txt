cmake_minimum_required(VERSION 3.0)

project(hello)

set(SRC main.cpp)
set(SRC_LIB hello_world.cpp)

add_library(hello_world STATIC ${SRC_LIB})

add_executable(main main.cpp)

target_link_libraries(main hello_world)
