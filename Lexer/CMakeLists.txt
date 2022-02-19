project(Lexer)

file(GLOB CPP_FILES src/*.cpp)
file(GLOB HEADER_FILES src/*.hpp)

add_library(Lexer ${CPP_FILES} ${HEADER_FILES})