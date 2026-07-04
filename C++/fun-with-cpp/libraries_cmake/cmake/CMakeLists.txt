# 1. It tell user should have at least this version of cmake to build the project
cmake_minimum_required(VERSION 3.10)

# 2. It tell the name of the project, it should come after "cmake_minimum_required"
project(app)

# 3. It tell the C++ standard to use for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Forces to use the C++ standard specified in the previous line

include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG master
)
FetchContent_MakeAvailable(raylib)

# 4. Following line tell the compiler where o look the ".h" (header) files, it's similar to "g++ -I raylib/include main.cpp -o app" in the terminal
#include_directories(raylib/include)

# 5.
#add_subdirectory(raylib)


# 7. It's the command to create an executable, it's similar to "g++ main.cpp -o app" in the terminal
add_executable(app main.cpp)

# 6.
target_link_libraries(app raylib)