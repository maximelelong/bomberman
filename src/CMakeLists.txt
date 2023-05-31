set(SOURCE_FILES
    main.cpp
    Case.cpp
    Game.cpp
    Player.cpp
    GameElement.cpp
    Terrain.cpp
    Block.cpp
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Set include directory search paths
target_include_directories(${PROJECT_NAME} 
  PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio)
