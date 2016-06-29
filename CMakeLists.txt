cmake_minimum_required(VERSION 3.5)
project(Hack_Assembler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CodeTranslator.cpp
    CodeTranslator.h
    main.cpp
    Parser.cpp
    Parser.h
    SymbolTable.cpp
    SymbolTable.h SymbolAddressPair.cpp SymbolAddressPair.h)

add_executable(chasm ${SOURCE_FILES})