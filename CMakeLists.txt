cmake_minimum_required(VERSION 3.15)
project(expreval VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_GENERATOR "Ninja")

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(
  expreval
  main.cpp
  src/debug.cpp
  src/expreval.cpp
  src/queue.cpp
  src/stack.cpp
)

target_compile_options(expreval PRIVATE -Wall -Wextra -Werror)
