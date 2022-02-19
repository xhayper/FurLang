project(FurLang)

file(GLOB CPP_FILES src/*.cpp)
file(GLOB HEADER_FILES src/*.hpp)

add_executable(FurLang ${CPP_FILES} ${HEADER_FILES})

target_link_libraries(FurLang PRIVATE Lexer)