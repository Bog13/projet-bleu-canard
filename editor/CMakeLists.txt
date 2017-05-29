cmake_minimum_required(VERSION 3.5)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}")
project(pbc-editor)

file(GLOB
  sources
  ../game/src/*.cpp
  src/*.cpp
  main.cpp
  )

include_directories("../game/include" "include")
add_executable(editor.elf ${sources})
target_link_libraries(editor.elf ${SFML_LDFLAGS})