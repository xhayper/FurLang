cmake_minimum_required(VERSION 3.22.2)
project(FurLang)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin)

# FILE(GLOB LEXER_LIBRARIES ${CMAKE_BINARY_DIR}/Lexer/*.cpp)
# include_directories(include ${LEXER_LIBRARIES})
# link_directories(lib ${CMAKE_BINARY_DIR}/out/lib)

include_directories(.)
link_directories(.)

add_subdirectory(Lexer)
add_subdirectory(CLI)