project(CLI)

file(GLOB SOURCE_FILES ${SOURCE_DIRECTORY}/*.cpp ${SOURCE_DIRECTORY}/*.c)
file(GLOB HEADER_FILES ${SOURCE_DIRECTORY}/*.hpp ${SOURCE_DIRECTORY}/*.h)

add_executable(${PROJECT_NAME} ${CPP_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} Parser)