cmake_minimum_required(VERSION 3.15)
project(bomberman)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# add dependencies: SFML
find_package(SFML 2.5 COMPONENTS system graphics audio window REQUIRED)
add_subdirectory(src)
