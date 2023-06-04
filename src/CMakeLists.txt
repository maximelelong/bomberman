file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} 
  PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio)

# for tests
add_library(${PROJECT_NAME}_lib ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME}_lib 
  PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(${PROJECT_NAME}_lib PUBLIC sfml-graphics sfml-audio sfml-system)