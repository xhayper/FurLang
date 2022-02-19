project(Lexer)

file(GLOB CPP_FILES src/*.cpp src/*.c)
file(GLOB HEADER_FILES src/*.hpp src/*.h)

add_library(${PROJECT_NAME} STATIC ${CPP_FILES} ${HEADER_FILES})