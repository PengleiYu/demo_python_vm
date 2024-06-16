cmake_minimum_required(VERSION 3.24)
project(demo_vm)

set(CMAKE_CXX_STANDARD 17)

#产物生成到源码目录，这样可以直接读取源码目录文件
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(demo_vm main.cpp Lexer.cpp Lexer.h)
