// main.cpp
#include "raylib.h"

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