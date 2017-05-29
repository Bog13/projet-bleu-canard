cmake_minimum_required(VERSION 3.5)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}")
project(pbc-game)

file(GLOB
  sources
  src/*.cpp
  main.cpp)

include_directories(include)
add_executable(pbc.elf ${sources})
target_link_libraries(pbc.elf ${SFML_LDFLAGS})