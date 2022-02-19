cmake_minimum_required(VERSION 3.22.2)
project(FurLang)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/main.cpp)

add_executable(FurLang ${SOURCE_FILES})

set_target_properties(FurLang
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/bin"
)