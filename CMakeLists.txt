cmake_minimum_required(VERSION 3.5)
project(Hack_Assembler_C__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    .idea/encodings.xml
    .idea/Hack-Assembler.iml
    .idea/misc.xml
    .idea/modules.xml
    .idea/vcs.xml
    .idea/workspace.xml
    CMakeLists.txt
    code.cpp
    code.h
    main.cpp
    parser.cpp
    parser.h
    symbolTable.cpp
    symbolTable.h)

add_executable(Hack_Assembler_C__ ${SOURCE_FILES})