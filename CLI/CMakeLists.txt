cmake_minimum_required(VERSION 3.22.2)
project(CLI)

file(GLOB CPP_FILES src/*.cpp src/*.c)
file(GLOB HEADER_FILES src/*.hpp src/*.h)

add_executable(${PROJECT_NAME} ${CPP_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} Lexer)