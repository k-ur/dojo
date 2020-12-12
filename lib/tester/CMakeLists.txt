cmake_minimum_required(VERSION 3.5)

project(lib_tester LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(lib) #インクルードディレクトリ指定
link_directories(lib) #ライブラリディレクトリ指定

add_executable(lib_tester main.cpp)
target_link_libraries(lib_tester a so)
