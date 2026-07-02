# 1. It tell user should have at least this version of cmake to build the project
cmake_minimum_required(VERSION 3.10)

# 2. It tell the name of the project, it should come after "cmake_minimum_required"
project(MyApp)

# 3. It tell the C++ standard to use for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Forces to use the C++ standard specified in the previous line


# 4. Following line tell the compiler where to look the ".h" (header) files, it's similar to "g++ -I raylib/include main.cpp -o app" in the terminal
#include_directories(raylib/include)

# 5.
#add_subdirectory(raylib)

# 6.
#target_link_libraries(app raylib)


# 7. It's the command to create an executable, it's similar to "g++ main.cpp -o app" in the terminal
add_executable(app main.cpp)
