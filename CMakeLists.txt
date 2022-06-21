cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_PROJECT "/usr/bin/clang++-14")
project(drweb_dictionary)
add_compile_options(-std=c++20 -O2)

add_executable(drweb_dictionary MAIN_drweb_dictionary.cpp test.cpp)
