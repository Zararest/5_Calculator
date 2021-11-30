cmake_minimum_required(VERSION 3.0.0)
project(Calculator VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Calculator src/main.cpp src/headers/DSL.h src/Calculator.cpp src/headers/Calculator.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
