project(Parser)

file(GLOB SOURCE_FILES ${SOURCE_DIRECTORY}/*.cpp ${SOURCE_DIRECTORY}/*.c)
file(GLOB HEADER_FILES ${SOURCE_DIRECTORY}/*.hpp ${SOURCE_DIRECTORY}/*.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${SOURCE_DIRECTORY}/)