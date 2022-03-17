cmake_minimum_required(VERSION 3.22.2)
project(FurLang)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_DIRECTORY src)

include_directories(include/)
link_directories(lib/)

add_subdirectory(Lexer)
add_subdirectory(CLI)