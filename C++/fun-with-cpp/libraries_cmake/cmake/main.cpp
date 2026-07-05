// main.cpp
#include "raylib.h"

int main() {
    InitWindow(800, 450, "Hello Raylib");

    const char* myName = "Abdur Rab Khan";

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello World", 190, 200, 20, WHITE);
        DrawCircle(100, 200, 60.0f, BLUE);
        DrawCircle(200, 200, 30, YELLOW);
        DrawText(myName, 200, 400, 20, YELLOW);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
