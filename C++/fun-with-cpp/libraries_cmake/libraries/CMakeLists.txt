# 1. It tell user should have at least this version of cmake to build the project
cmake_minimum_required(VERSION 3.10)

# 2. It tell the name of the project, it should come after "cmake_minimum_required"
project(MyApp)

# 3. It tell the C++ standard to use for the project

# 4.
add_executable(app main.cpp raylib/libraylib.a)