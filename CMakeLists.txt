cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 17)

project(todo)

aux_source_directory(./src SRC)

add_executable(${PROJECT_NAME} ${SRC})
