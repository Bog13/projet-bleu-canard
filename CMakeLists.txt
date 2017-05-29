cmake_minimum_required(VERSION 3.5)

project(pbc)

find_package(PkgConfig)
pkg_check_modules(SFML sfml-all)

add_subdirectory(game)
add_subdirectory(editor)