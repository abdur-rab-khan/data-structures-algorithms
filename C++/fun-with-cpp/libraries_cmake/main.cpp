// main.cpp
#include "raylib/src/raylib.h"

/*
 * [ Learn Commands to Compile C++ Code ]:
 *                                         To compile this code, we are going to use "g++", let's see some options:
 * -I<path>
 *   Compiler first looks in current directory,
 *   then standard include paths (/usr/include/).
 *   -I adds extra path to search for .h files.
 *
 * -L<path>
 *   Linker first looks in standard library paths (/usr/lib/).
 *   -L adds extra path to search for .a or .so files.
 *
 * -l<library>
 *   Tells linker WHICH library to link.
 *   It is not a path — it is a name.
 *   Linker looks for lib+name+.a in all known paths.
 */

int main() {
    InitWindow(800, 450, "Hello Raylib");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello World", 190, 200, 20, WHITE);
        DrawCircle(100, 200, 60.0f, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
