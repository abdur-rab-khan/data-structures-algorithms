# 1. It tell user should have at least this version of cmake to build the project
cmake_minimum_required(VERSION 3.10)

# 2. It tell the name of the project, it should come after "cmake_minimum_required"
project(app)

# 3. It tell the C++ standard to use for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Forces to use the C++ standard specified in the previous line

include_directories(raylib/raylib.h)

# 4.
add_executable(app main.cpp raylib/libraylib.a)