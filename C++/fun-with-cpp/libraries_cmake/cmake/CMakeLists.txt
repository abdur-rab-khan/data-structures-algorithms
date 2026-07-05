# 1. It tell user should have at least this version of cmake to build the project
cmake_minimum_required(VERSION 4.4)

# 2. It tell the name of the project, it should come after "cmake_minimum_required"
project(app)

# 3. It tell the C++ standard to use for the project, and other options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Forces to use the C++ standard specified in the previous line
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Tell "CMake" to create "compile_commands.json" file also, So that we can tell where "header" files are there to ".clangd"

set(CMAKE_POLICY_VERSION_MINIMUM 3.10)

# a. Release (no bug helpers, faster, for real use)
# b. Debug (helps you find bugs, slower)
set(CMAKE_BUILD_TYPE Release)

# 4. Used to download the third party library and build automatically, if they have "CMakeLists.txt" file and include into the program automatically.
#    It's similar to "add_subdirectory" but here we don't manually git clone.
include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)
message(STATUS "Raylib downloaded successfully")

# 5. If we have a library that have there own, "CMakeLists.txt" we can provide this command than "CMake" will build automatically and include it, See "FetchContent"
#add_subdirectory(raylib)

# 4. Following line tell the compiler where o look the ".h" (header) files, it's similar to "g++ -I raylib/include main.cpp -o app" in the terminal
#include_directories(raylib/include) --> target_include_directories(name [PRIVATE | PUBLIC | INTERFACE] path), it's modern way to include header files

# 7. It's the command to create an executable, it's similar to "g++ main.cpp -o app" in the terminal
add_executable(app main.cpp)

# 8.
# find_library()

# 4. It's used to tell linker where "-o, -so" object files are there, good when we have build-in "-o, -so" file and want to old CMake about those files, similar to "-L"
# target_link_directories([executable_name] [PRIVATE] path)

# 6. It's used to link, libraries so that linker know what libraries do i need to add for this program it's similar to "-l[library name]"
target_link_libraries(app PRIVATE raylib)

# 🏗️ Ways to build from "CMakeLists.txt"
# 1. Make "Makefile" to do this we use this command [cmake -G ["Ninja" | "MinGW Makefiles"] -B [dir_name]] --- Build to set .exe file [cmake --build [dir_name]
# 2. Create build file and go inside, than build using this command [cmake -G "[MinGW Makefiles | Ninja]" ".. (path where CMakeLists.txt where)" after than either ninja or makefile will created and we can use "make" or "ninja" command to get .exe file
