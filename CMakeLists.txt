cmake_minimum_required(VERSION 3.12.3)
project(RPN)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(RPN main.cpp src/AbstractOperation.cpp src/AbstractOperation.h src/BuildReversePolishNotation.cpp src/BuildReversePolishNotation.h src/Calculator.cpp src/Calculator.h src/CollectionOperations.cpp src/CollectionOperations.h)
