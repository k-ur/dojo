cmake_minimum_required(VERSION 3.14)

project(so LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(so SHARED
  so_global.h
  so.cpp
  so.h
)

target_compile_definitions(so PRIVATE SO_LIBRARY)
