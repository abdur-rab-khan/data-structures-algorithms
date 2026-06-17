cmake_minimum_required(VERSION 3.15)

project(raylib)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

add_executable(my_game src/main.cpp)

target_link_libraries(my_game raylib)