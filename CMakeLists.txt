cmake_minimum_required(VERSION 3.5)
project(Hack_Assembler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp parser.cpp parser.h code.cpp code.h symbolTable.cpp symbolTable.h)
add_executable(Hack_Assembler ${SOURCE_FILES})