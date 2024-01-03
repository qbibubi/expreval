cmake_minimum_required(VERSION 3.25)
project(expreval VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")

add_executable(expreval
  src/main.cpp
  src/evaluator/evaluator.cppm
  src/evaluator/evaluator.cpp
)
