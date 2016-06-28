cmake_minimum_required(VERSION 3.5)
project(Hack_Assembler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    .idea/encodings.xml
    .idea/Hack-Assembler.iml
    .idea/misc.xml
    .idea/modules.xml
    .idea/vcs.xml
    .idea/workspace.xml
    CMakeLists.txt
        Code.cpp
        Code.h
    main.cpp
        Parser.cpp
        Parser.h
        SymbolTable.cpp
        SymbolTable.h)

add_executable(chasm ${SOURCE_FILES})