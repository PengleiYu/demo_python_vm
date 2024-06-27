cmake_minimum_required(VERSION 3.24)
project(demo_vm)

set(CMAKE_CXX_STANDARD 17)

#产物生成到源码目录，这样可以直接读取源码目录文件
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(demo_vm main.cpp parse/lexer.cpp parse/lexer.h parse/ast.cpp parse/ast.h parse/visitor.cpp parse/visitor.h parse/parser.cpp parse/parser.h parse/codeObj.cpp parse/codeObj.h parse/codeGen.cpp parse/codeGen.h parse/op_code.h)
