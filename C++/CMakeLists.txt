cmake_minimum_required(VERSION 3.5)

project(grep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(grep
  file_list.cpp
  search_line.cpp
  main.cpp
  )
