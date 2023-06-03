project(bomberman DESCRIPTION "[Projet C++ ROB4] Bomberman" LANGUAGES CXX)

# CMake version
cmake_minimum_required(VERSION 3.15)
# Set C++ standard
set (CMAKE_CXX_FLAGS "-lstdc++fs -std=c++17")
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Dependencies: SFML and CTest
find_package(SFML 2.5 COMPONENTS system graphics audio window REQUIRED)
include(CTest)

# Source files and ressources
add_subdirectory(src)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})


# Add tests
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

