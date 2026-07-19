cmake_minimum_required(VERSION 4.4)

project(TodoApp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Release)

add_executable(
  todo
  src/main.cpp
  src/Todo.cpp
  src/TodoManager.cpp
)
